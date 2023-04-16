/*
** EPITECH PROJECT, 2022
** t_class_sprite_animator.h
** File description:
** desc
*/
#ifndef t_class_sprite_animator
    #define t_class_sprite_animator

    #include <stdbool.h>
    #include "t_sprite_animation.h"
    #include <t_hashmap.h>

    typedef struct animator {
        struct sprite *host;
        int animation_frame;
        t_hashmap_node *played_animation;
        t_hashmap *map_animation;
        t_hashmap_node *default_animation;
        t_list *list_callback;
        int64_t last_clock_update;
    } animator;

    typedef struct animation_callback {
        char *animation_name;
        void (*callback)(struct sprite *);
    } animation_callback;

    int animator_update_frame(animator *self, sfClock *clock);
    bool animator_play_animation(animator *self, char *animation_name);
    bool animator_add_animation(animator *self, animation *new_animation);
    bool animator_remove_animation(animator *self, char *animation_name);
    t_hashmap_node *animator_have_animation(animator *self
        , char *animation_name);
    bool animator_set_default(animator *self, char *animation_name);
    animator *new_animator(struct sprite *self);
    void animator_callback(animator *self, char *animation_name);
    bool animator_add_callback(animator *self, char *animation_name
        , void (*call_back)(struct sprite *sprite_pointer));
    bool animator_remove_callback(animator *self, tsize_t index);
    void animator_remove_callback_by_name(animator *self, char *animation_name);
    void update_sprite_animator(struct sprite *sprite, sfClock *clock);
#endif //t_class_sprite_animator
