#include <switch_min.h>
#include <stdint.h>
#include <stdlib.h>
#include <cmath>

#include "useful/const_value_table.h"
#include "useful/crc32.h"
#include "useful/raygun_printer.h"
#include "useful/useful.h"

#include "saltysd/nn_ro.h"

#include "acmd_wrapper.h"
#include "acmd_edits.h"

using namespace lib;
using namespace app::sv_animcmd;
using namespace app::lua_bind;

extern u64 boma_array[8]; // array defined to store player numbers.
extern u64 get_kind(u64) asm("_ZN3app7utility8get_kindEPKNS_26BattleObjectModuleAccessorE") LINKABLE;

L2CAgent* fighter_agents[8];
u64 fighter_module_accessors[8];

u64 prev_get_command_flag_cat = 0;
u64 prev_clear_lua_stack = 0;

// Checks for the player's number. Meant for use in boma_array that stores each character's number in a match
// Example: 0 == player 1, 7 == player 8
int get_player_number(u64 &boma){
    int entry_id = WorkModule::get_int(boma, FIGHTER_INSTANCE_WORK_ID_INT_ENTRY_ID);
    return entry_id;
}

// Sets the battle object pertaining to fighters in the boma array.
void write_boma(u64 &boma){
    u8 fighter_category = (u8)(*(u32*)(boma + 8) >> 28);
    if(fighter_category == BATTLE_OBJECT_CATEGORY_FIGHTER){
        boma_array[get_player_number(boma)] = boma;
    }
}

u64 __init_settings(u64 &boma, u64 &situation_kind, int &param_3, u64 &param_4, u64 &param_5, bool &param_6, int &param_7,int &param_8,int &param_9,int &param_10) {
    u64 status_module = load_module(boma, 0x40);
    for (size_t i = 0; i < 8; i++){
        boma_array[i] = 0;
    }
    u64 (*init_settings)(u64, u64, u64, u64, u64, u64, u64, u64) = (u64 (*)(u64, u64, u64, u64, u64, u64, u64, u64))(load_module_impl(status_module, 0x1c8));
    return init_settings(status_module, situation_kind, param_3, param_4, param_5, param_6, param_7, param_8);
}

// Function involving new mechanics for Joker 
void joker_string(u64 &boma, int &status_kind, int &situation_kind){
    u8 fighter_category = (u8)(*(u32*)(boma + 8) >> 28);
    int fighter_kind = get_kind(boma);
    u64 control_module = load_module(boma, 0x48);
    int (*get_command_flag_cat)(u64,int) = (int (*)(u64,int))load_module_impl(control_module, 0x350);
    int cat = get_command_flag_cat(control_module, 0);
    int cat2 = get_command_flag_cat(control_module, 1);
    
    if (fighter_category == BATTLE_OBJECT_CATEGORY_FIGHTER){
		
		//This statement will allow Joker to cancel his aerial attacks, dash attack, and tilt attacks by pressing shield or air dodge
		//Occurs on the condition that Arsene exists on screen
        if (fighter_kind == FIGHTER_KIND_JACK && WorkModule::is_flag(boma, FIGHTER_JACK_INSTANCE_WORK_ID_FLAG_DOYLE_EXIST) == true)
            if (status_kind == FIGHTER_STATUS_KIND_ATTACK_AIR || status_kind == FIGHTER_STATUS_KIND_ATTACK_DASH 
            || status_kind == FIGHTER_STATUS_KIND_ATTACK_HI3 || status_kind == FIGHTER_STATUS_KIND_ATTACK_S3 || status_kind == FIGHTER_STATUS_KIND_ATTACK_LW3){ 
            if (AttackModule::is_infliction_status(boma, 2) == true){
                if ((cat & FIGHTER_PAD_CMD_CAT1_ESCAPE) || (cat2 & FIGHTER_PAD_CMD_CAT2_FLAG_COMMON_GUARD)){
                    //print_string(boma, "check");
                    DamageModule::add_damage(boma, 2, 0);  
                }
            }
        }

		// If Joker summons Arsene, the animation is sped up by 2.75
		// If Joker is in the ground the statement will check for a jump or dash input, jump only if in the air
		// If the conditions are true, then the summon effect will immediately transition in a dash or jump respectively
        if (fighter_kind == FIGHTER_KIND_JACK && status_kind == FIGHTER_JACK_STATUS_KIND_SUMMON){
                MotionModule::set_rate(boma, 2.75);
                if (situation_kind == SITUATION_KIND_GROUND){
                    if (ControlModule::check_button_on(boma, CONTROL_PAD_BUTTON_JUMP) == true || (cat & FIGHTER_PAD_CMD_CAT1_FLAG_JUMP_BUTTON))
                        StatusModule::change_status_request_from_script(boma, FIGHTER_STATUS_KIND_JUMP, true);
                    if (ControlModule::get_stick_x(boma) == -1 || ControlModule::get_stick_x(boma) == 1)
                        StatusModule::change_status_request_from_script(boma, FIGHTER_STATUS_KIND_DASH, true);
                }
                if (situation_kind == SITUATION_KIND_AIR){
                    if (ControlModule::check_button_on(boma, CONTROL_PAD_BUTTON_JUMP) == true)
                        StatusModule::change_status_request_from_script(boma, FIGHTER_STATUS_KIND_JUMP_AERIAL, true);
                }
        }

		//If Joker uses a Down Special, then he will immediately transition to a special animation after frame 9.
        if (fighter_kind == FIGHTER_KIND_JACK){
            if (status_kind == FIGHTER_JACK_STATUS_KIND_SPECIAL_LW_ATTACK){
                if (MotionModule::frame(boma) > 9){
                    StatusModule::change_status_request_from_script(boma, FIGHTER_JACK_STATUS_KIND_SUMMON, true);
                }
            }  
        }
    }
}

// Function that replicates how Sheik's neutral special works in Smash Bros Melee
void melee_needle(u64 &boma, int &status_kind){
    u8 fighter_category = (u8)(*(u32*)(boma + 8) >> 28);
    int fighter_kind = get_kind(boma);

	// If Sheik charges the needle, releasing the button will shoot all the needles previously charged
    if (fighter_category == BATTLE_OBJECT_CATEGORY_FIGHTER && fighter_kind == FIGHTER_KIND_SHEIK){
        if (status_kind == FIGHTER_SHEIK_STATUS_KIND_SPECIAL_N_LOOP){
            if (ControlModule::check_button_on_release(boma, CONTROL_PAD_BUTTON_SPECIAL) == true){
                StatusModule::change_status_request_from_script(boma, FIGHTER_SHEIK_STATUS_KIND_SPECIAL_N_SHOOT, true);
            }
        }
    }
}

//Function that involves changes in fighter's interacting with the ledge and actions with jab attack
void ledgeaction(u64 &boma, int &status_kind, int &situation_kind){
    float current_frame = MotionModule::frame(boma); //takes the frame function defined in lua_bind that calculates any current frame
    u8 fighter_category = (u8)(*(u32*)(boma + 8) >> 28);

	//Checks if a fighter is on a cliff. Statement checks for a c-stick input that changes ledge attack into the fighter dropping like in Smash Bros Melee
    if (fighter_category == BATTLE_OBJECT_CATEGORY_FIGHTER){
        if (situation_kind == SITUATION_KIND_CLIFF){
            if (ControlModule::check_button_on(boma, CONTROL_PAD_BUTTON_CSTICK_ON) == true && current_frame == 1){
                if (status_kind == FIGHTER_STATUS_KIND_CLIFF_ATTACK)
                    StatusModule::change_status_request_from_script(boma, FIGHTER_STATUS_KIND_FALL, true);
            }
        }
    }

	// If a fighter jabs, they cannot hold the button to continually jab over and over again.
    if (fighter_category == BATTLE_OBJECT_CATEGORY_FIGHTER){
        if (status_kind == FIGHTER_STATUS_KIND_ATTACK){
            WorkModule::off_flag(boma, FIGHTER_STATUS_ATTACK_FLAG_ENABLE_RESTART);
            WorkModule::set_flag(boma, false, FIGHTER_STATUS_ATTACK_FLAG_ENABLE_RESTART);
        }

        if (situation_kind == SITUATION_KIND_AIR){
            if (status_kind == FIGHTER_STATUS_KIND_FALL_SPECIAL || status_kind == FIGHTER_STATUS_KIND_SPECIAL_HI)
                GroundModule::set_cliff_check(boma, GROUND_CLIFF_CHECK_KIND_ALWAYS_BOTH_SIDES);
            else
                GroundModule::set_cliff_check(boma, GROUND_CLIFF_CHECK_KIND_ON_DROP);
        }
        if (status_kind == FIGHTER_STATUS_KIND_ESCAPE_AIR){
                GroundModule::set_cliff_check(boma, GROUND_CLIFF_CHECK_KIND_NONE);
        }
    }
}

//Melee styled dash dancing, when you dash the other way there is only 1 frame of wait status before transitioning into an opposite dash
void turndash(u64 &boma, int &status_kind){
    float current_frame = MotionModule::frame(boma);
    if (status_kind == FIGHTER_STATUS_KIND_TURN_DASH) {
        StatusModule::change_status_request_from_script(boma, FIGHTER_STATUS_KIND_WAIT, true);
        PostureModule::reverse_lr(boma);
        if(status_kind == FIGHTER_STATUS_KIND_WAIT && current_frame == 1) {
            StatusModule::change_status_request_from_script(boma, FIGHTER_STATUS_KIND_DASH, true);
        }
    }
}

int get_command_flag_cat_replace(u64 module_accessor, int category) {
    int (*prev_replace)(u64, int) = (int (*)(u64, int)) prev_get_command_flag_cat;
    if (prev_replace)
        prev_replace(module_accessor, category);

    u64 control_module = load_module(module_accessor, 0x48);
    int (*get_command_flag_cat)(u64, int) = (int (*)(u64, int)) load_module_impl(control_module, 0x350);
    int flag = get_command_flag_cat(control_module, category);

    if (category == 0) {
        int fighter_entry = WorkModule::get_int(module_accessor, FIGHTER_INSTANCE_WORK_ID_INT_ENTRY_ID);
        L2CAgent* l2c_agent = fighter_agents[fighter_entry];
        if (fighter_module_accessors[fighter_entry] == module_accessor && l2c_agent && l2c_agent->lua_state_agent 
            && app::sv_system::battle_object_module_accessor(l2c_agent->lua_state_agent) == module_accessor) {
            for (ACMD& acmd_obj : acmd_objs)
                acmd_obj.run(l2c_agent);
        }
    }

    int status_kind = StatusModule::status_kind(module_accessor);
    int situation_kind = StatusModule::situation_kind(module_accessor);
	
	//the following functions below are called here in get_command_flag_cat() that runs every frame inside the game executable. 
	//These functions are called every frame during the a match 
    write_boma(module_accessor);
    joker_string(module_accessor, status_kind, situation_kind);
    melee_needle(module_accessor, status_kind);
    ledgeaction(module_accessor, status_kind, situation_kind);
    turndash(module_accessor, status_kind);
 

    return flag;
}

void replace_scripts(L2CAgent* l2c_agent, u8 category, int kind) {
    // fighter
    if (category == BATTLE_OBJECT_CATEGORY_FIGHTER) {
        u64 module_accessor = app::sv_system::battle_object_module_accessor(l2c_agent->lua_state_agent);
        int fighter_entry = WorkModule::get_int(module_accessor, FIGHTER_INSTANCE_WORK_ID_INT_ENTRY_ID);
        fighter_module_accessors[fighter_entry] = module_accessor;
        fighter_agents[fighter_entry] = l2c_agent;

        for (ACMD& acmd_obj : acmd_objs)
            acmd_obj.nullify_original(l2c_agent);
    }
}

void* sv_get_status_func(u64 l2c_agentbase, int status_kind, u64 key) {
    u64 unk48 = LOAD64(l2c_agentbase + 0x48);
    u64 unk50 = LOAD64(l2c_agentbase + 0x50);
    if (0x2E8BA2E8BA2E8BA3LL * ((unk50 - unk48) >> 4) > (u64)status_kind)
        return *(void**)(unk48 + 0xB0LL * status_kind + (key << 32 >> 29));

    return 0;
}

void sv_replace_status_func(u64 l2c_agentbase, int status_kind, u64 key, void* func) {
    u64 unk48 = LOAD64(l2c_agentbase + 0x48);
    u64 unk50 = LOAD64(l2c_agentbase + 0x50);
    if (0x2E8BA2E8BA2E8BA3LL * ((unk50 - unk48) >> 4) > (u64)status_kind) {
        *(void**)(unk48 + 0xB0LL * status_kind + (key << 32 >> 29)) = func;
    }
}

u64 clear_lua_stack_replace(L2CAgent* l2c_agent) {
    u64 (*prev_replace)(L2CAgent*) = (u64 (*)(L2CAgent*)) prev_clear_lua_stack;
    if (prev_replace)
        prev_replace(l2c_agent);

    u64 lua_state = l2c_agent->lua_state_agent;
    if ((lua_state - 8) && 
        LOAD64(lua_state - 8) &&
        (LOAD64(LOAD64(lua_state - 8) + 416LL))) {
        u8 battle_object_category = *(u8*)(LOAD64(lua_state - 8) + 404LL);
        int battle_object_kind = *(int*)(LOAD64(lua_state - 8) + 408LL);
        replace_scripts(l2c_agent, battle_object_category, battle_object_kind);
    }

    return l2c_agent->_clear_lua_stack();
}

void script_replacement() {
    SaltySD_function_replace_sym_check_prev(
        "_ZN3app8lua_bind40ControlModule__get_command_flag_cat_implEPNS_26BattleObjectModuleAccessorEi",
        (u64)&get_command_flag_cat_replace,
        prev_get_command_flag_cat);
    SaltySD_function_replace_sym_check_prev(
        "_ZN3lib8L2CAgent15clear_lua_stackEv", 
        (u64)&clear_lua_stack_replace,
        prev_clear_lua_stack);
}