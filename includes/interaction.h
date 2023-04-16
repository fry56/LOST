/*
** EPITECH PROJECT, 2023
** interaction.h
** File description:
** desc
*/
#ifndef interaction
    #define interaction

    #include <Class/t_sprite.h>

    typedef struct interaction_t {
        sprite *host;
        float interaction_dist;
        void *datas;
        void (*onInteract)(sprite *sprite_datas, struct interaction_t *);
    } interaction_s;

#endif //interaction
