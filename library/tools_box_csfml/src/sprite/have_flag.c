/*
** EPITECH PROJECT, 2022
** have_flag.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "t_string.h"

bool sprite_have_flag(sprite *self, char *flag)
{
    list_foreach(self->list_flags, node) {
        if (tstr_cmp(node->value, flag) == 0)
            return true;
    }
    return false;
}
