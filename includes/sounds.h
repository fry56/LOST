/*
** EPITECH PROJECT, 2023
** sounds.h
** File description:
** desc
*/
#ifndef sounds
    #define sounds

    #include <t_ctype.h>

    typedef struct sound_t {
        char *name;
        char *path;
        float min_dist;
        float volume;
        bool loop;
        bool over_play;
    } sound_s;

#endif //sounds
