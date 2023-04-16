/*
** EPITECH PROJECT, 2023
** rpg_weapon.h
** File description:
** desc
*/
#ifndef rpg_weapon
    #define rpg_weapon

    #include "t_ctype.h"
    #include <SFML/Graphics.h>

    #define NBR_WEAPONS_TYPES 4

    typedef enum weapons_type_t {
        weapon_knife = 0,
        weapon_handgun,
        weapon_rifle,
        weapon_shotgun,
        weapon_undefined
    } weapons_type_e;

    typedef struct weapon_config_t {
        weapons_type_e type;
        char *name;

        char *weapon_path;
        char *ammo_path;

        int magazin_size;
        int max_ammos;

        float fire_rate;
        float melee_rate;
        float reload_time;

        float shoot_range;
        float melee_range;

        int shoot_damage;
        int melee_damage;

        char *sound_reload;
        char *sound_shoot;
        char *sound_empty;
        char *sound_melee;
    } weapon_config_s;

    typedef struct weapon_t {
        weapons_type_e type;
        int32_t loaded_ammos;
        int32_t ammos;
        uint64_t shoot;
        uint64_t melee;
        bool unlock;
    } weapon_s;

    typedef struct weapon_object_t {
        weapons_type_e type;
        int32_t loaded_ammos;
    } weapon_object_s;

    typedef struct ammos_object_t {
        weapons_type_e type;
    } ammos_object_s;

    typedef struct weapons_manager_t {
        weapons_type_e equiped_weapon;
        weapon_s weapons[NBR_WEAPONS_TYPES];
        uint64_t timestamp_weapon_change;
        uint64_t timestamp_wait;
    } weapons_manager_s;

#endif //rpg_weapon
