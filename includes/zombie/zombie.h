/*
** EPITECH PROJECT, 2023
** zombie.h
** File description:
** desc
*/
#ifndef zombie
    #define zombie

    #define NBR_ZOMBIES_TYPES 1

    #include "t_list.h"
    #include "zombie_animations_config.h"
    #include "Class/t_sprite.h"
    #include <Class/t_sound_manager.h>
    #include <pathfinding/pathfinding.h>
    #include <box_collider/box_collider.h>

    typedef enum zombie_status_t {
        idle = 0,
        trigger,
        death
    } zombie_status_e;

    typedef struct zombie_t {
        sprite *host;
        uint16_t type;
        sound_mananger *sound_mgr;
        int health;
        zombie_status_e status;
        pathfinding_entity_s *pathfinding_mgr;
        uint64_t timestamp_interaction;
        box_collider_s *box_collider;
    } zombie_s;

    // ZOMBIE //
    sprite *zombie_init(scene *scene_datas, sfVector2f pos);

    void zombie_destroy(sprite *sprite_datas);
    void zombie_move(sprite *sprite_datas, sfVector2f pos);
    void zombie_set_pos(sprite *sprite_datas, sfVector2f pos);
    void zombie_damage(sprite *sprite_datas, uint16_t amount);
    void zombie_set_trigger(sprite *sprite_datas);

    void zombie_load_animations(window *window_datas);
    void zombie_load_sounds(window *window_datas);

    entity_animation_s get_zombie_anim_by_type(zombie_s *zombie_datas,
        entity_animation_type_e type);

    void zombie_init_sound_mgr(scene *scene_datas, sprite *new_zombie);
    void zombie_init_animations(scene *scene_datas, sprite *new_zombie);
    void zombie_init_pathfinding(zombie_s *zombie_datas);

    void zombie_event_move(sprite *sprite_datas, sfClock *clock);
#endif //zombie
