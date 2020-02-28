#include <switch_min.h>

#include <stdint.h>

#include "useful/const_value_table.h"
#include "useful/raygun_printer.h"
#include "useful/useful.h"

#include "acmd_wrapper.h"

using namespace lib;
using namespace app::sv_animcmd;
using namespace app::lua_bind;
using namespace app::sv_math;
using namespace app::sv_kinetic_energy;
using namespace app::sv_battle_object;
using namespace app::sv_module_access;
using namespace app::FL_sv_module_access;
using namespace app::sv_system;


ACMD acmd_objs[] = {
    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_CHROM", "attack_air_lw", "gameattackairlw",
        [] (ACMD* acmd) -> void{
        acmd->frame(3);
        if (acmd->is_excute()) {
            WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
        acmd->frame(16);
        if (acmd->is_excute()) { 
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 14.25, /*Angle*/ 270, /*KBG*/ 90, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 4.4, /*X*/ 0.0, /*Y*/ -0.7, /*Z*/ 0.4, /*X2*/ 0.0, /*Y2*/ -2.5, /*Z2*/ 0.4, /*Hitlag*/ 1.2, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_CHROM_HIT, /*Type*/ ATTACK_REGION_SWORD);
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 14.25, /*Angle*/ 80, /*KBG*/ 90, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 4.4, /*X*/ 0.0, /*Y*/ -0.7, /*Z*/ 0.4, /*X2*/ 0.0, /*Y2*/ -2.5, /*Z2*/ 0.4, /*Hitlag*/ 1.2, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_CHROM_HIT, /*Type*/ ATTACK_REGION_SWORD);
            acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 11.875, /*Angle*/ 80, /*KBG*/ 90, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 5.4, /*X*/ 0.0, /*Y*/ -6.8, /*Z*/ 0.4, /*X2*/ 0.0, /*Y2*/ -1.0, /*Z2*/ 0.4, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_CHROM_HIT, /*Type*/ ATTACK_REGION_SWORD);
        }
        acmd->frame(29);
        if (acmd->is_excute()) {
            AttackModule::clear_all(acmd->module_accessor);
        }
        acmd->frame(52);
        if (acmd->is_excute()) {
            WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }

    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_PEACH", "attack_dash", "game_attackdash",
        [] (ACMD* acmd) -> void{
        acmd->frame(6); //strong hit on frame 6
        if (acmd->is_excute()) {    
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 12.0, /*Angle*/ 80, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 70, /*Size*/ 3.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 5.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 12.0, /*Angle*/ 80, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 70, /*Size*/ 4.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 10.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 9.0, /*Angle*/ 45, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 50, /*Size*/ 3.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 5.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 3, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 9.0, /*Angle*/ 45, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 50, /*Size*/ 4.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 10.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->wrap(ATK_SET_SHIELD_SETOFF_MUL_arg5, { /*ID1*/ L2CValue(0), /*ID2*/ L2CValue(1), /*ID3*/ L2CValue(2), /*ID4*/ L2CValue(3), /*ShieldstunMul*/ L2CValue(2.9) });
        }
        acmd->frame(9); //weak hit on frame 9?
        if (acmd->is_excute()) {    
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 8.0, /*Angle*/ 80, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 3.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 5.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_SLAP, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 8.0, /*Angle*/ 80, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 4.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 10.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_SLAP, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 7.0, /*Angle*/ 45, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 3.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 5.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_SLAP, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 3, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 7.0, /*Angle*/ 45, /*KBG*/ 70, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 4.0, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 10.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_magic"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_SLAP, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->wrap(ATK_SET_SHIELD_SETOFF_MUL_arg5, { /*ID1*/ L2CValue(0), /*ID2*/ L2CValue(1), /*ID3*/ L2CValue(2), /*ID4*/ L2CValue(3), /*ShieldstunMul*/ L2CValue(2.9) });
        }

        acmd->frame(20); //clear all on frame 20
        if (acmd->is_excute()) {
            AttackModule::clear_all(acmd->module_accessor);
        }

    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_PEACH", "attack_air_b", "game_attackairb", 
        [] (ACMD* acmd) -> void{
            acmd->frame(5);
            if (acmd->is_excute()) {
                WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
            }
            acmd->frame(6);
            if (acmd->is_excute()) {     
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 14.0, /*Angle*/ 361, /*KBG*/ 100, /*FKB*/ 0, /*BKB*/ 0, /*Size*/ 6.0, /*X*/ 0.0, /*Y*/ 8.0, /*Z*/ -5.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_HIP);
            }
            acmd->frame(10);
            if (acmd->is_excute()) {    
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 10.0, /*Angle*/ 361, /*KBG*/ 90, /*FKB*/ 0, /*BKB*/ 10, /*Size*/ 6.0, /*X*/ 0.0, /*Y*/ 8.0, /*Z*/ -5.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_HIP);
            }
            acmd->frame(23);
            if (acmd->is_excute()) {
                AttackModule::clear_all(acmd->module_accessor);
            }
            acmd->frame(30);
            if (acmd->is_excute()) {
                WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
            }
        }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_PEACH", "attack_air_lw", "game_attackairlw", 
        [] (ACMD* acmd) -> void{
            acmd->frame(12);
            for(size_t i = 0; i < 3; i++){
                if (acmd->is_excute()) {
                    acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 3.0, /*Angle*/ 90, /*KBG*/ 50, /*FKB*/ 0, /*BKB*/ 16, /*Size*/ 5.5, /*X*/ 0.0, /*Y*/ -1.0, /*Z*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("0x13135c5462"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                    acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 2.0, /*Angle*/ 90, /*KBG*/ 50, /*FKB*/ 0, /*BKB*/ 12, /*Size*/ 4.5, /*X*/ 0.0, /*Y*/ 4.0, /*Z*/ -0.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("0x13135c5462"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                }
                acmd->wait(2);
                if (acmd->is_excute()) {
                    AttackModule::clear_all(acmd->module_accessor);
                }
                acmd->wait(4);
            }
            if (acmd->is_excute()) {
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 3.0, /*Angle*/ 90, /*KBG*/ 50, /*FKB*/ 0, /*BKB*/ 16, /*Size*/ 6.5, /*X*/ 0.0, /*Y*/ -1.0, /*Z*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 2.0, /*Angle*/ 90, /*KBG*/ 50, /*FKB*/ 0, /*BKB*/ 12, /*Size*/ 5.5, /*X*/ 0.0, /*Y*/ 4.0, /*Z*/ -0.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
            }
            acmd->wait(2);
            if (acmd->is_excute()) {
                AttackModule::clear_all(acmd->module_accessor);
            }
            acmd->frame(38);
            if (acmd->is_excute()) {
                WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
            }
        }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_PEACH", "attack_lw4", "game_attacklw4", 
        [] (ACMD* acmd) -> void{
        acmd->frame(3);
        if (acmd->is_excute()) {
        WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_FLAG_START_SMASH_HOLD);
        }
        for(size_t i = 0; i < 6; i++){
            if (acmd->is_excute()) {
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 12.0, /*Angle*/ 140, /*KBG*/ 80, /*FKB*/ 0, /*BKB*/ 35, /*Size*/ 2.5, /*X*/ -2.5, /*Y*/ 2.0, /*Z*/ 0.0, /*X2*/ 2.5, /*Y2*/ 2.0, /*Z2*/ 0.0, /*Hitlag*/ 0.5, /*SDI*/ 0.5, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_BODY);
                acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 14.0, /*Angle*/ 155, /*KBG*/ 80, /*FKB*/ 0, /*BKB*/ 40, /*Size*/ 4.3, /*X*/ -2.5, /*Y*/ 2.0, /*Z*/ 7.5, /*X2*/ 2.5, /*Y2*/ 2.0, /*Z2*/ 7.5, /*Hitlag*/ 0.5, /*SDI*/ 0.5, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_BODY);	
                acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 14.0, /*Angle*/ 155, /*KBG*/ 80, /*FKB*/ 0, /*BKB*/ 40, /*Size*/ 4.3, /*X*/ -2.5, /*Y*/ 2.0, /*Z*/ -7.5, /*X2*/ 2.5, /*Y2*/ 2.0, /*Z2*/ -7.5, /*Hitlag*/ 0.5, /*SDI*/ 0.5, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_BODY);	
                AttackModule::set_attack_height_all(acmd->module_accessor, ATTACK_HEIGHT_LOW, false);
            }
            acmd->wait(2);
            if (acmd->is_excute()) {
                AttackModule::clear_all(acmd->module_accessor);
            }
            acmd->wait(2);
        }
        if (acmd->is_excute()) {
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 14.0, /*Angle*/ 140, /*KBG*/ 80, /*FKB*/ 0, /*BKB*/ 40, /*Size*/ 4.3, /*X*/ 0.0, /*Y*/ 1.8, /*Z*/ 7.5, /*X2*/ 0.0, /*Y2*/ 1.8, /*Z2*/ -7.5, /*Hitlag*/ 3.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_BODY);
            AttackModule::set_attack_height_all(acmd->module_accessor, ATTACK_HEIGHT_LOW, false);
        }
        acmd->wait(2);
        if (acmd->is_excute()) {
            AttackModule::clear_all(acmd->module_accessor);
        }

    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_CAPTAIN", "attack_air_b", "game_attackairb",
        [] (ACMD* acmd) -> void{
            acmd->frame(5);
            if (acmd->is_excute()) {
	
                WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
            }
            acmd->frame(10);
            if (acmd->is_excute()) {
	
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("arml"), /*Damage*/ 13.0, /*Angle*/ 361, /*KBG*/ 97, /*FKB*/ 0, /*BKB*/ 27, /*Size*/ 5.5, /*X*/ 4.0, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
	            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 13.0, /*Angle*/ 361, /*KBG*/ 97, /*FKB*/ 0, /*BKB*/ 27, /*Size*/ 4.0, /*X*/ 3.2, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
	            acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 13.0, /*Angle*/ 361, /*KBG*/ 97, /*FKB*/ 0, /*BKB*/ 27, /*Size*/ 4.0, /*X*/ -0.8, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
            }
            acmd->wait(2);
            if (acmd->is_excute()) {
	
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("arml"), /*Damage*/ 8.0, /*Angle*/ 361, /*KBG*/ 97, /*FKB*/ 0, /*BKB*/ 27, /*Size*/ 5.5, /*X*/ 4.0, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
                acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 8.0, /*Angle*/ 361, /*KBG*/ 97, /*FKB*/ 0, /*BKB*/ 27, /*Size*/ 4.0, /*X*/ 3.2, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
	            acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 8.0, /*Angle*/ 361, /*KBG*/ 97, /*FKB*/ 0, /*BKB*/ 27, /*Size*/ 4.0, /*X*/ -0.8, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
            }
            acmd->wait(4);
            if (acmd->is_excute()) {
                AttackModule::clear_all(acmd->module_accessor);
            }
            acmd->wait(3);
            if (acmd->is_excute()) {
                WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
            }
    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_JACK", "attack_air_f", "game_attackairf",
        [] (ACMD* acmd) -> void{
            acmd->frame(4);
            if (acmd->is_excute()) {
                WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
            }
            acmd->frame(7);
            if (acmd->is_excute()) {	
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("legr"), /*Damage*/ 2.0, /*Angle*/ 367, /*KBG*/ 25, /*FKB*/ 0, /*BKB*/ 70, /*Size*/ 4.0, /*X*/ 3.2, /*Y*/ 0.0, /*Z*/ 0.0, /*X2*/ 3.2, /*Y2*/ -0.5, /*Z2*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_S, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("legr"), /*Damage*/ 2.0, /*Angle*/ 76, /*KBG*/ 50, /*FKB*/ 0, /*BKB*/ 73, /*Size*/ 4.0, /*X*/ 3.2, /*Y*/ 0.0, /*Z*/ 0.0, /*X2*/ 3.2, /*Y2*/ 0.0, /*Z2*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_S, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("kneer"), /*Damage*/ 2.0, /*Angle*/ 367, /*KBG*/ 5, /*FKB*/ 0, /*BKB*/ 70, /*Size*/ 4.0, /*X*/ 4.2, /*Y*/ -0.7, /*Z*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_S, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                acmd->ATTACK(/*ID*/ 3, /*Part*/ 0, /*Bone*/ hash40("kneer"), /*Damage*/ 2.0, /*Angle*/ 80, /*KBG*/ 50, /*FKB*/ 0, /*BKB*/ 73, /*Size*/ 4.0, /*X*/ 4.2, /*Y*/ -0.7, /*Z*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_S, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                acmd->ATTACK(/*ID*/ 4, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 3.0, /*Angle*/ 367, /*KBG*/ 25, /*FKB*/ 0, /*BKB*/ 70, /*Size*/ 4.0, /*X*/ 0.0, /*Y*/ 8.5, /*Z*/ 10.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_S, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                acmd->ATTACK(/*ID*/ 5, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 3.0, /*Angle*/ 76, /*KBG*/ 50, /*FKB*/ 0, /*BKB*/ 73, /*Size*/ 4.0, /*X*/ 0.0, /*Y*/ 8.5, /*Z*/ 10.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ true, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_G, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_S, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
            }
            acmd->frame(8);
            if (acmd->is_excute()) {
                AttackModule::clear(acmd->module_accessor, /*ID*/ 4, false);
                AttackModule::clear(acmd->module_accessor, /*ID*/ 5, false);
            }
            acmd->frame(9);
            if (acmd->is_excute()) {
                AttackModule::clear_all(acmd->module_accessor);
            }
            acmd->frame(12);
            if (acmd->is_excute()) {
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("kneel"), /*Damage*/ 5.0, /*Angle*/ 361, /*KBG*/ 125, /*FKB*/ 0, /*BKB*/ 46, /*Size*/ 3.5, /*X*/ 4.4, /*Y*/ -0.7, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
                acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("legl"), /*Damage*/ 5.0, /*Angle*/ 361, /*KBG*/ 125, /*FKB*/ 0, /*BKB*/ 46, /*Size*/ 3.5, /*X*/ 3.2, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_KICK);
            }
            if (acmd->is_excute()) {
                if (acmd->is_excute()) {
                    AttackModule::clear(acmd->module_accessor, /*ID*/ 1, false);	
                    acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 5.0, /*Angle*/ 34, /*KBG*/ 148, /*FKB*/ 0, /*BKB*/ 48, /*Size*/ 6.0, /*X*/ 0.0, /*Y*/ 13.5, /*Z*/ 5.0, /*X2*/ 0.0, /*Y2*/ 13.5, /*Z2*/ 7.5, /*Hitlag*/ 1.9, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_HEAVY, /*Type*/ ATTACK_REGION_KICK);	
                    acmd->ATTACK(/*ID*/ 1, /*Part*/ 1, /*Bone*/ hash40("top"), /*Damage*/ 8.0, /*Angle*/ 34, /*KBG*/ 98, /*FKB*/ 0, /*BKB*/ 58, /*Size*/ 6.0, /*X*/ 0.0, /*Y*/ 13.5, /*Z*/ 5.0, /*X2*/ 0.0, /*Y2*/ 13.5, /*Z2*/ 7.5, /*Hitlag*/ 1.6, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_HEAVY, /*Type*/ ATTACK_REGION_KICK);
                    acmd->ATTACK(/*ID*/ 2, /*Part*/ 1, /*Bone*/ hash40("top"), /*Damage*/ 8.0, /*Angle*/ 34, /*KBG*/ 98, /*FKB*/ 0, /*BKB*/ 58, /*Size*/ 7.0, /*X*/ 0.0, /*Y*/ 18.0, /*Z*/ 5.0, /*X2*/ 0.0, /*Y2*/ 17.0, /*Z2*/ 6.5, /*Hitlag*/ 1.6, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_HEAVY, /*Type*/ ATTACK_REGION_KICK);
                }
            }
            acmd->wait(3);
            if (acmd->is_excute()) {
                AttackModule::clear_all(acmd->module_accessor);
            }
            acmd->frame(42);
            if (acmd->is_excute()) {
                WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
            }
    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_BUDDY", "attack_air_f", "game_attackairf",
        [] (ACMD* acmd) -> void{
        acmd->frame(3);
        if (acmd->is_excute()) { 
            WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
        acmd->frame(15);
        if (acmd->is_excute()) {    
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 15.0, /*Angle*/ 270, /*KBG*/ 86, /*FKB*/ 0, /*BKB*/ 36, /*Size*/ 4.2, /*X*/ 1.4, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.4, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("arml"), /*Damage*/ 16.0, /*Angle*/ 270, /*KBG*/ 86, /*FKB*/ 0, /*BKB*/ 36, /*Size*/ 4.8, /*X*/ 4.8, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.4, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
        }
        acmd->wait(3);
        if (acmd->is_excute()) {   
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 12.0, /*Angle*/ 44, /*KBG*/ 84, /*FKB*/ 0, /*BKB*/ 34, /*Size*/ 4.2, /*X*/ 1.4, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.2, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH); 
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("arml"), /*Damage*/ 12.0, /*Angle*/ 44, /*KBG*/ 84, /*FKB*/ 0, /*BKB*/ 34, /*Size*/ 4.8, /*X*/ 4.8, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.2, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_PUNCH, /*Type*/ ATTACK_REGION_PUNCH);
        }
        acmd->wait(1);
        if (acmd->is_excute()) { 
            AttackModule::clear_all(acmd->module_accessor);
        }
        acmd->frame(37);
        if (acmd->is_excute()) { 
            WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_CLOUD", "attack_air_lw", "game_attackairlw",
        [] (ACMD* acmd) -> void{
        acmd->frame(5);
        if (acmd->is_excute()) {
            WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
        acmd->frame(11);
        if (acmd->is_excute()) {
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("haver"), /*Damage*/ 15.0, /*Angle*/ 270, /*KBG*/ 100, /*FKB*/ 0, /*BKB*/ 10, /*Size*/ 3.6, /*X*/ 0.0, /*Y*/ 11.0, /*Z*/ 0.0, /*X2*/ 0.0, /*Y2*/ 12.5, /*Z2*/ 0.0, /*Hitlag*/ 1.5, /*SDI*/ 1.0, /*ClangRebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*DirectIndirect*/ true, /*GroundAir*/ COLLISION_SITUATION_MASK_A, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_CLOUD_HIT, /*Type*/ ATTACK_REGION_SWORD);
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("haver"), /*Damage*/ 13.0, /*Angle*/ 270, /*KBG*/ 105, /*FKB*/ 0, /*BKB*/ 30, /*Size*/ 4.5, /*X*/ 0.0, /*Y*/ 7.0, /*Z*/ 0.0, /*X2*/ 0.0, /*Y2*/ 13.0, /*Z2*/ 0.0, /*Hitlag*/ 1.2, /*SDI*/ 1.0, /*ClangRebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*DirectIndirect*/ true, /*GroundAir*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_CLOUD_HIT, /*Type*/ ATTACK_REGION_SWORD);
        }
        acmd->wait(8);
        if (acmd->is_excute()) {
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("haver"), /*Damage*/ 8.0, /*Angle*/ 65, /*KBG*/ 55, /*FKB*/ 0, /*BKB*/ 80, /*Size*/ 3.5, /*X*/ 0.0, /*Y*/ 9.0, /*Z*/ 0.0, /*X2*/ 0.0, /*Y2*/ 11.0, /*Z2*/ 0.0, /*Hitlag*/ 1.2, /*SDI*/ 1.0, /*ClangRebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*DirectIndirect*/ true, /*GroundAir*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_cutup"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_M, /*SFXType*/ COLLISION_SOUND_ATTR_CLOUD_HIT, /*Type*/ ATTACK_REGION_SWORD);   
            AttackModule::clear(acmd->module_accessor, /*ID*/ 0, false);
        }
        acmd->wait(26);
        if (acmd->is_excute()) {
            AttackModule::clear_all(acmd->module_accessor);
        }
        acmd->frame(46);
        if (acmd->is_excute()) {   
            WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_GANON", "special_n", "game_specialn",
        [] (ACMD* acmd) -> void{
        acmd->frame(11);
        if (acmd->is_excute()) {
            WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_GANON_STATUS_WORK_ID_FLAG_GANON_PUNCH_TURN);
            acmd->wrap(damage, { L2CValue(MA_MSC_DAMAGE_DAMAGE_NO_REACTION), L2CValue(DAMAGE_NO_REACTION_MODE_ALWAYS), L2CValue(0) });
        }
        acmd->frame(68);
        if (acmd->is_excute()) {
            acmd->wrap(damage, { L2CValue(MA_MSC_DAMAGE_DAMAGE_NO_REACTION), L2CValue(DAMAGE_NO_REACTION_MODE_NORMAL), L2CValue(0) });
        }
        acmd->frame(70);
        if (acmd->is_excute()) {
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 30.0, /*Angle*/ 180, /*KBG*/ 46, /*FKB*/ 0, /*BKB*/ 120, /*Size*/ 5.0, /*X*/ 2.4, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_purple"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("bust"), /*Damage*/ 30.0, /*Angle*/ 180, /*KBG*/ 46, /*FKB*/ 0, /*BKB*/ 120, /*Size*/ 4.7, /*X*/ 0.0, /*Y*/ 1.0, /*Z*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_purple"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_PUNCH);
            acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("arml"), /*Damage*/ 30.0, /*Angle*/ 180, /*KBG*/ 46, /*FKB*/ 0, /*BKB*/ 120, /*Size*/ 4.8, /*X*/ 5.0, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_purple"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_PUNCH);
        }
        if (acmd->is_excute()) {
            if (acmd->is_excute()) {
                acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("shoulderl"), /*Damage*/ 30.0, /*Angle*/ 180, /*KBG*/ 46, /*FKB*/ 0, /*BKB*/ 120, /*Size*/ 5.0, /*X*/ 1.5, /*Y*/ 0.0, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_purple"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_PUNCH);
                acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("bust"), /*Damage*/ 30.0, /*Angle*/ 180, /*KBG*/ 46, /*FKB*/ 0, /*BKB*/ 120, /*Size*/ 4.7, /*X*/ 1.1, /*Y*/ -0.3, /*Z*/ -0.4, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_purple"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_PUNCH);
                acmd->ATTACK(/*ID*/ 2, /*Part*/ 0, /*Bone*/ hash40("arml"), /*Damage*/ 30.0, /*Angle*/ 180, /*KBG*/ 46, /*FKB*/ 0, /*BKB*/ 120, /*Size*/ 4.8, /*X*/ 1.0, /*Y*/ -4.0, /*Z*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_F, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_purple"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_PUNCH);
            }
        }
        acmd->frame(74);
        if (acmd->is_excute()) {
            AttackModule::clear_all(acmd->module_accessor);
        }
    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_PIKACHU", "attack_air_lw", "game_attackairlw",
        [] (ACMD* acmd) -> void{
        if (acmd->is_excute()) {
            WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
        acmd->frame(14);
        if (acmd->is_excute()) {
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("neck"), /*Damage*/ 13.0, /*Angle*/ 270, /*KBG*/ 86, /*FKB*/ 0, /*BKB*/ 16, /*Size*/ 5.5, /*X*/ 2.5, /*Y*/ -1.3, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_elec"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_ELEC, /*Type*/ ATTACK_REGION_HEAD);
        }
        acmd->frame(18);
        if (acmd->is_excute()) {
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("neck"), /*Damage*/ 12.0, /*Angle*/ 361, /*KBG*/ 84, /*FKB*/ 0, /*BKB*/ 20, /*Size*/ 5.7, /*X*/ 2.5, /*Y*/ -1.3, /*Z*/ 0.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_elec"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_ELEC, /*Type*/ ATTACK_REGION_HEAD);
        }
        acmd->wait(11);
        if (acmd->is_excute()) {
            AttackModule::clear_all(acmd->module_accessor);
        }
        acmd->wait(12);
        if (acmd->is_excute()) {
            WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
    }),

    ACMD("BATTLE_OBJECT_CATEGORY_FIGHTER", "FIGHTER_KIND_INKLING", "attack_air_lw", "game_attackairlw",
        [] (ACMD* acmd) -> void{
        acmd->frame(5);
        if (acmd->is_excute()) {
            WorkModule::on_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
        acmd->frame(16);
        if (acmd->is_excute()) {
            acmd->ATTACK(/*ID*/ 0, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 10.0, /*Angle*/ 361, /*KBG*/ 60, /*FKB*/ 0, /*BKB*/ 60, /*Size*/ 3.5, /*X*/ 0.0, /*Y*/ 3.5, /*Z*/ 0.5, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_OBJECT);
            acmd->ATTACK(/*ID*/ 1, /*Part*/ 0, /*Bone*/ hash40("top"), /*Damage*/ 12.0, /*Angle*/ 270, /*KBG*/ 72, /*FKB*/ 0, /*BKB*/ 30, /*Size*/ 5.0, /*X*/ 0.0, /*Y*/ -2.0, /*Z*/ 1.0, /*X2*/ 0.0, /*Y2*/ -4.0, /*Z2*/ 1.0, /*Hitlag*/ 1.0, /*SDI*/ 1.0, /*Clang/Rebound*/ ATTACK_SETOFF_KIND_ON, /*FacingRestrict*/ ATTACK_LR_CHECK_POS, /*SetWeight*/ false, /*ShieldDamage*/ 0, /*Trip*/ 0.0, /*Rehit*/ 0, /*Reflectable*/ false, /*Absorbable*/ false, /*Flinchless*/ false, /*DisableHitlag*/ false, /*Direct/Indirect*/ true, /*Ground/Air*/ COLLISION_SITUATION_MASK_GA, /*Hitbits*/ COLLISION_CATEGORY_MASK_ALL, /*CollisionPart*/ COLLISION_PART_MASK_ALL, /*FriendlyFire*/ false, /*Effect*/ hash40("collision_attr_normal"), /*SFXLevel*/ ATTACK_SOUND_LEVEL_L, /*SFXType*/ COLLISION_SOUND_ATTR_KICK, /*Type*/ ATTACK_REGION_OBJECT);
        }
        acmd->wait(8);
        if (acmd->is_excute()) {
            AttackModule::clear_all(acmd->module_accessor);
        }
        acmd->frame(33);
        if (acmd->is_excute()) {
            WorkModule::off_flag(acmd->module_accessor, /*Flag*/ FIGHTER_STATUS_ATTACK_AIR_FLAG_ENABLE_LANDING);
        }
    }),
};