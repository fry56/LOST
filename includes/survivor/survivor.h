/*
** EPITECH PROJECT, 2023
** rpg_player.h
** File description:
** desc
*/
#ifndef survivor
    #define survivor

    #include "inventory/inventory.h"
    #include "weapon/weapon.h"
    #include "t_list.h"
    #include "survivor_animations_config.h"
    #include "Class/t_sprite.h"
    #include <Class/t_sound_manager.h>
    #include "survivor_movements_config.h"
    #include <interaction.h>
    #include <box_collider/box_collider.h>
    #include <pathfinding/pathfinding.h>

    typedef struct survivor_t {
        sprite *host;
        weapons_manager_s *weapon_mgr;
        sound_mananger *sound_mgr;
        inventory_mgr_s *inventory_mgr;
        int health;
        bool freeze;
        pathfinding_node_s *pathfinding_node;
        box_collider_s *box_collider;
        sfVector2f mouse_pos;
        sfKeyCode actual_movement;
        uint64_t timestamp_interaction;
        float angle;
    } survivor_s;


    // SURVIVOR //
    bool survivor_init_datas(window *window_datas);
    sprite *survivor_init(scene *scene_datas, sfVector2f pos);

    void survivor_init_inventory_mgr(survivor_s *survivor_datas);
    void survivor_init_weapon_mgr(survivor_s *survivor_datas);
    void survivor_init_sound_mgr(scene *scene_datas, sprite *new_player);
    void survivor_init_animations(scene *scene_datas, sprite *new_player);

    void survivor_destroy(sprite *sprite_datas);
    void survivor_set_pos(sprite *sprite_datas, sfVector2f pos);
    void survivor_move(sprite *sprite_datas, sfVector2f pos);

    void survivor_load_sounds(window *window_datas);
    void survivor_load_animations(window *window_datas);

    // SURVIVOR EVENT //
    void survivor_event_mouse_move(sprite *sprite_datas, window *window_datas);
    void survivor_event_mouse_click(sprite *sprite_datas, window *window_datas);
    void survivor_event_movements(sprite *sprite_datas, sfClock *clock UNUSED);
    void survivor_event_weapon_reload(sprite *sprite_datas,
        window *window_datas);
    void survivor_event_interactions(sprite *sprite_datas,
        window *window_datas);
    void survivor_event_space(sprite *sprite_datas, window *window_datas);

    entity_animation_s get_survivor_anim_by_type(survivor_s *survivor_datas,
        entity_animation_type_e type);

    // WEAPON //
    void weapon_change(sprite *sprite_datas, window *window_datas);
    void weapon_shoot(sprite *sprite_datas, uint64_t timestamp);
    void weapon_reload(sprite *sprite_datas, uint64_t timestamp);
    void weapon_set(sprite *sprite_datas, weapons_type_e type);
    void weapon_add_ammos(sprite *sprite_datas, weapons_type_e type,
        uint16_t amount);
    void weapon_melee(sprite *sprite_datas, sfUint64 timestamp);

    // OBJECT INTERACTIONS //
    void weapon_object_interact(sprite *sprite_datas,
        interaction_s *interaction_datas);
    sprite *new_weapon_object(scene *scene_datas, sfVector2f pos, float angle,
        weapons_type_e type);
    void weapon_object_destroy(sprite *sprite_datas);

    void ammos_object_interact(sprite *sprite_datas,
        interaction_s *interaction_datas);
    sprite *new_ammos_object(scene *scene_datas, sfVector2f pos, float angle,
        weapons_type_e type);
    void ammos_object_destroy(sprite *sprite_datas);

    // INVENTORY //
    inventory_item_s *inventory_get_item_by_name(inventory_mgr_s *inventory_mgr,
        char *item_name);
    bool inventory_add_item(survivor_s *survivor_datas, char *item_name,
        uint16_t amount);
    uint16_t inventory_have_item(survivor_s *survivor_datas, char *item_name);
    bool inventory_remove_item(survivor_s *survivor_datas, char *item_name,
        uint16_t amount);
    bool inventory_set_item(survivor_s *survivor_datas, char *item_name,
        uint16_t amount);
    bool inventory_use_item(survivor_s *survivor_datas, char *item_name);

#endif
