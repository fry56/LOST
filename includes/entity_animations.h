/*
** EPITECH PROJECT, 2023
** animation.h
** File description:
** desc
*/
#ifndef animations
    #define animations

    #include "t_ctype.h"
    #include <SFML/Graphics.h>
    #include "Class/t_window.h"

    typedef enum entity_animation_type_t {
        anim_idle = 0,
        anim_melee,
        anim_move,
        anim_reload,
        anim_shoot,
        anim_death,
        anim_particles,
        unknown
    } entity_animation_type_e;

    typedef struct entity_animation_t {
        entity_animation_type_e type;
        char *name;
        char *path;
        int nbr_sprite;
        int nbr_sprite_per_ligne;
        sfIntRect rect_start;
        bool loop;
        bool end_freeze;
        bool custom_origin;
        sfVector2f origin;
        float frame_rate;
    } entity_animation_s;

    void entitys_load_animations(window *window_datas,
        entity_animation_s tmp_anim_conf);
#endif //animation
