/*
** EPITECH PROJECT, 2022
** set_string.c
** File description:
** desc
*/

#include <Class/t_text.h>
#include <t_string.h>

void text_set_content(text *self, char *content)
{
    if (tstr_len(content) == 0)
        return;
    sfText_setString(self->sf_text, content);
}
