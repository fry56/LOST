/*
** EPITECH PROJECT, 2023
** entity_sounds.h
** File description:
** desc
*/
#ifndef entity_sounds
    #define entity_sounds

    #include <t_ctype.h>

    typedef enum entity_sounds_type_t {
        sound_idle = 0,
        sound_melee,
        sound_move,
        sound_reload,
        sound_shoot,
        sound_death,
        sound_damage,
        sound_trigger,
        sound_unknown
    } entity_sounds_type_e;

    typedef struct entity_sound_t {
        char *name;
        entity_sounds_type_e type;
        char *path;
        float min_dist;
        float volume;
        bool loop;
        bool over_play;
    } entity_sound_s;

    entity_sound_s get_random_sound_by_type(const entity_sound_s *config,
        entity_sounds_type_e type);

#endif //entity_sounds
