/*
** EPITECH PROJECT, 2023
** t_sound_mananger.h
** File description:
** desc
*/
#ifndef t_sound_mananger
    #define t_sound_mananger

    #include <t_hashmap.h>
    #include "t_sound.h"
    #include <Class/t_scene.h>

    typedef struct sound_mananger {
        scene *host;
        t_hashmap *map_sound;
        t_list *list_sound_manager_player;
        sfInt64 timestamp_play;
        t_hashmap_node *node_default_sound;
        t_list_node *node_sound_manager;
        sfVector2f pos;
        float min_dist;
        float volume;
    } sound_mananger;

    typedef struct sound_manager_player {
        sound_mananger *host;
        sound *sound_datas;
        sfSound *sf_sound;
        uint64_t timestamp_destroy;
        t_list_node *node_sound_manager_player;
        bool destroy;
    } sound_manager_player;

    sound_mananger *new_sound_manager(scene *scene_datas, sfVector2f pos,
        float min_dist, float volume);
    bool sound_manager_add_sound(sound_mananger *self, sound *sound_datas);
    bool sound_manager_play_sound(sound_mananger *self, char *name);
    void sound_manager_destroy(sound_mananger *self);
    void sound_manager_stop_sound(sound_mananger *self, char *name);
    void sound_manager_remove_sound(sound_mananger *self, char *name);
    void clear_sound_manager_player(sound_mananger *self, sfClock *clock);
    void sound_manager_destroy_player(sound_manager_player *self);
    void sound_manager_clear(sound_mananger *self);
    bool sound_manager_set_default(sound_mananger *self, char *name);
    void sound_manager_set_pos(sound_mananger *self, sfVector2f pos);
    void sound_manager_move(sound_mananger *self, sfVector2f pos);
#endif //t_sound_mananger
