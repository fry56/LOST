/*
** EPITECH PROJECT, 2022
** t_class_text.h
** File description:
** desc
*/
#ifndef t_class_text
    #define t_class_text

    #include "Utils/t_rgb.h"
    #include <SFML/Graphics.h>
    #include "t_ctype.h"
    #include "t_list.h"
    #include "t_scene.h"

    typedef struct text {
        scene *host;
        t_list_node *text_node;

        bool visible;
        void *datas;

        sfVector2f pos;
        t_list *list_flags;
        sfText *sf_text;
        sfFont *sf_font;
        sfColor sf_color;

        void (*destroy)(struct text *);
        void (*move)(struct text *, sfVector2f pos);
        void (*set_pos)(struct text *, sfVector2f pos);
    } text;

    void text_move(text *self, sfVector2f pos);
    text *new_text(scene *scene_datas, char *content
        , char *font, rgb rgb);
    void text_set_content(text *self, char *content);
    void text_set_font_color(text *self, rgb rgb);
    void text_set_font_size(text *self, uint32_t font_size);
    void text_set_pos(text *self, sfVector2f pos);
    bool text_add_flag(text *self, char *flag);
    bool text_remove_flag(text *self, char *flag);
    bool text_have_flag(text *self, char *flag);
    void text_destroy(text *self);
    void text_set_origin_center(text *self);
#endif //t_class_text
