/*
** EPITECH PROJECT, 2023
** raycast.h
** File description:
** desc
*/
#ifndef raycast_h
    #define raycast_h

    #include <Class/t_sprite.h>

    bool raycast(sfVector2f start, sfVector2f end,
        double angle, float clerance);
    sprite *raycast_nearest_sprite_by_flag(sprite *sprite_datas, float range,
        char *flag);

#endif //raycast
