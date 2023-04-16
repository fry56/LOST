/*
** EPITECH PROJECT, 2022
** have_flag.c
** File description:
** desc
*/

#include <Class/t_text.h>
#include <t_string.h>

bool text_have_flag(text *self, char *flag)
{
    list_foreach(self->list_flags, node) {
        if (tstr_cmp(node->value, flag) == 0)
            return true;
    }
    return false;
}
