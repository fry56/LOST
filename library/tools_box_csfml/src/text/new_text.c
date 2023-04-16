/*
** EPITECH PROJECT, 2022
** new_text.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_text.h>
#include <stdlib.h>
#include <t_string.h>
#include <t_assert.h>
#include <t_mem.h>

void init_new_text(text *new_text, char *content, rgb rgb)
{
    new_text->move = NULL;
    new_text->set_pos = NULL;
    new_text->destroy = NULL;
    new_text->visible = true;
    new_text->pos = (sfVector2f){0, 0};
    tassert((new_text->sf_text = sfText_create()) == NULL);
    new_text->sf_color = sfColor_fromRGB(rgb.red, rgb.green, rgb.blue);
    sfText_setFont(new_text->sf_text, new_text->sf_font);
    sfText_setString(new_text->sf_text, content);
    sfText_setColor(new_text->sf_text, new_text->sf_color);
    new_text->list_flags = tlist_new();
}

text *new_text(scene *scene_datas, char *content,
    char *font, rgb rgb)
{
    text *new_text = tcalloc(1, sizeof(text));
    t_list_node *new_text_node;

    t_assert(new_text == NULL);
    new_text_node = tlist_add(scene_datas->list_texts, new_text);
    if (font == NULL)
        font = "assets/font/Fruit Days.ttf";
    tassert((new_text->sf_font = sfFont_createFromFile(font)) == NULL);
    new_text->host = scene_datas;
    new_text->text_node = new_text_node;
    init_new_text(new_text, content, rgb);
    return new_text;
}
