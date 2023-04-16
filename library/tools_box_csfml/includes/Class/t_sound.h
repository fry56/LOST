/*
** EPITECH PROJECT, 2023
** t_sound.h
** File description:
** desc
*/
#ifndef t_sound
    #define t_sound

    #include <SFML/Audio.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/Export.h>
    #include <t_ctype.h>

    typedef struct sound {
        char *name;
        float min_dist;
        float volume;
        bool loop;
        bool over_play;
        sfInt64 duration;
        sfSoundBuffer *sf_sound_buffer;
    } sound;

    sound *new_sound(char *name, char *path, float min_dist, float volume);
    void sound_destroy(sound *self);
#endif //t_sound
