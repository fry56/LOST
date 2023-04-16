/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_sprite_animator.h>
#include "Class/t_sprite.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <t_assert.h>

void sprite_garbadg_destroy(void *datas)
{
    tsize_t i = 0;
    sprite *self = datas;

    if (self->destroy != NULL)
        self->destroy(self);
    sfSprite_destroy(self->sf_sprite);
    if (self->sf_texture != NULL)
        sfTexture_destroy(self->sf_texture);
    if (self->animator != NULL) {
        list_foreach(self->animator->list_callback, node) {
            animator_remove_callback(self->animator, i);
            i++;
        }
        thashmap_clear(self->animator->map_animation);
        free(self->animator);
    }
    tlist_clear(self->list_flags);
    tlist_remove(self->sprite_node->host, self->sprite_node);
}

void sprite_destroy(sprite *self)
{
    window_add_garbage(self->host->host, self->sprite_node,
        sprite_garbadg_destroy);
}
