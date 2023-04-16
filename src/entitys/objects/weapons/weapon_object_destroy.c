/*
** EPITECH PROJECT, 2023
** weapon_object_destroy.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <interaction.h>
#include <stdlib.h>

void weapon_object_destroy(sprite *sprite_datas)
{
    interaction_s *interaction_datas = sprite_datas->datas;
    free(interaction_datas->datas);
    free(interaction_datas);
}
