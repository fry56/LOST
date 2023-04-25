/*
** EPITECH PROJECT, 2023
** weapon_config.h
** File description:
** desc
*/
#ifndef weapon_config
    #define weapon_config

    #include "weapon.h"

    static weapon_config_s weapons_config[] UNUSED = {
        {
            weapon_knife,
            "Couteau",
            "assets/sprites/items/weapons/weapon_knife.png",
            NULL,
            0,
            0,
            0,
            10.0f,
            0,
            0,
            150,
            0,
            20,
            NULL,
            NULL,
            NULL,
            "sound_weapon_knife_shoot"
        },
        {
            weapon_handgun,
            "Glock 19",
            "assets/sprites/items/weapons/weapon_glock_19.png",
            "assets/sprites/items/ammos/ammo_handgun.png",
            15,
            90,
            2.0f,
            10.0f,
            10.0f,
            550,
            150,
            40,
            10,
            "sound_weapon_handgun_reload",
            "sound_weapon_handgun_shoot",
            "sound_weapon_handgun_empty",
            "sound_weapon_handgun_melee"
        },
        {
            weapon_rifle,
            "AK47",
            "assets/sprites/items/weapons/weapon_ak47.png",
            "assets/sprites/items/ammos/ammo_rifle.png",
            30,
            120,
            0.5f,
            10.0f,
            10.0f,
            750,
            150,
            50,
            15,
            "sound_weapon_rifle_reload",
            "sound_weapon_rifle_shoot_end",
            "sound_weapon_rifle_empty",
            "sound_weapon_handgun_melee"
        },
        {
            weapon_shotgun,
            "Maverick",
            "assets/sprites/items/weapons/weapon_maveric.png",
            "assets/sprites/items/ammos/ammo_shotgun.png",
            6,
            32,
            10.0f,
            10.0f,
            10.0f,
            500,
            150,
            70,
            15,
            "sound_weapon_shotgun_reload",
            "sound_weapon_shotgun_shoot",
            "sound_weapon_shotgun_empty",
            "sound_weapon_handgun_melee"
        }
    };

#endif
