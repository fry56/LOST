/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_text.h>
#include <Class/t_scene.h>

void text_garbadg_destroy(void *datas)
{
    text *self = datas;
    if (self->destroy != NULL)
        self->destroy(self);
    sfText_destroy(self->sf_text);
    sfFont_destroy(self->sf_font);
    tlist_free(self->list_flags);
    tlist_remove(self->text_node->host, self->text_node);
}

void text_destroy(text *self)
{
    window_add_garbage(self->host->host, self->text_node,
        text_garbadg_destroy);
}
