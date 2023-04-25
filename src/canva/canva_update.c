/*
** EPITECH PROJECT, 2023
** canva_init.c
** File description:
** desc
*/

#include <Class/t_scene.h>
#include <Class/t_sprite.h>

void canva_update(scene *scene_datas, sfVector2f offset)
{
    sprite *temp_sprite;

    list_foreach(scene_datas->list_sprites, node) {
        temp_sprite = node->value;
        if (!sprite_have_flag(temp_sprite, "canva"))
            continue;
        sprite_move(temp_sprite, offset);
    }
}
