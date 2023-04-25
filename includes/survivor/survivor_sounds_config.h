/*
** EPITECH PROJECT, 2023
** survivor_sounds_config.h
** File description:
** desc
*/
#ifndef survivor_sounds_config
    #define survivor_sounds_config

    #include <sounds.h>

    static const sound_s survivor_sound_config[] = {
        {
            "sound_survivor_bandage",
            "assets/sound/survivor/bandage.ogg",
            250,
            100,
            false,
            false
        },
        {
            "sound_survivor_craft",
            "assets/sound/survivor/craft.ogg",
            250,
            100,
            false,
            false
        },
        {
            "sound_survivor_footstep",
            "assets/sound/survivor/footstep.ogg",
            250,
            100,
            false,
            false
        },
        {
            "sound_survivor_equip",
            "assets/sound/survivor/equip.ogg",
            250,
            15,
            false,
            false
        },
        {
            "sound_survivor_grab",
            "assets/sound/survivor/grab.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_survivor_hurt_1",
            "assets/sound/survivor/hurt_1.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_survivor_death",
            "assets/sound/survivor/death.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_survivor_hurt_2",
            "assets/sound/survivor/hurt_2.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_survivor_hurt_3",
            "assets/sound/survivor/hurt_3.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_handgun_empty",
            "assets/sound/weapons/handgun/handgun_empty.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_handgun_melee",
            "assets/sound/weapons/handgun/handgun_melee.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_handgun_reload",
            "assets/sound/weapons/handgun/handgun_reload.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_handgun_shoot",
            "assets/sound/weapons/handgun/handgun_shoot.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_knife_shoot",
            "assets/sound/weapons/knife/knife_shoot.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_rifle_empty",
            "assets/sound/weapons/rifle/rifle_empty.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_rifle_reload",
            "assets/sound/weapons/rifle/rifle_reload.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_rifle_shoot",
            "assets/sound/weapons/rifle/rifle_shoot.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_rifle_shoot_end",
            "assets/sound/weapons/rifle/rifle_shoot_end.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_shotgun_empty",
            "assets/sound/weapons/shotgun/shotgun_empty.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_shotgun_reload",
            "assets/sound/weapons/shotgun/shotgun_reload.ogg",
            250,
            100,
            false,
            true
        },
        {
            "sound_weapon_shotgun_shoot",
            "assets/sound/weapons/shotgun/shotgun_shoot.ogg",
            250,
            100,
            false,
            true
        },
        {
            NULL,
            NULL,
            0,
            0,
            false,
            false
        }
    };

#endif //survivor_sounds_config
