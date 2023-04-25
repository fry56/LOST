/*
** EPITECH PROJECT, 2023
** weapon_hud.h
** File description:
** desc
*/
#ifndef weapon_hud
    #define weapon_hud

    #include <Class/t_sprite.h>
    #include <Class/t_text.h>

    typedef struct weapon_hud_t {
        sprite *host;
        text *description;
        sfVector2f pos;
    } weapon_hud_s;

#endif //weapon_hud
