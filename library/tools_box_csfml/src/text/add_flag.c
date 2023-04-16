/*
** EPITECH PROJECT, 2022
** add_flag.c
** File description:
** desc
*/

#include <Class/t_text.h>
#include <t_string.h>

bool text_add_flag(text *self, char *flag)
{
    if (text_have_flag(self, flag))
        return false;
    tlist_add(self->list_flags, tstr_cpy(NULL, flag));
    return true;
}
