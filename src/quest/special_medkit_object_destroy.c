/*
** EPITECH PROJECT, 2023
** item_object_destroy.c
** File description:
** desc
*/
#include <Class/t_sprite.h>
#include <interaction.h>
#include <stdlib.h>


void special_medkit_object_destroy(sprite *sprite_datas)
{
    interaction_s *interaction_datas = sprite_datas->datas;
    free(interaction_datas);
}
