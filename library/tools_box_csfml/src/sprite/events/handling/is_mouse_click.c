/*
** EPITECH PROJECT, 2022
** is_mouse_over.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
struct converted_pos_s {
    sfFloatRect sprite_bounds;
    sfVector2f pos;
    sfVector2f origin;
    sfVector2f scale;
};

static struct converted_pos_s get_pos(sprite *self)
{
    sfVector2u size = sfRenderWindow_getSize(self->host->host->window);
    sfVideoMode default_size = self->host->host->mode;
    float x_a = ((float)size.x / (float)default_size.width);
    float y_a = ((float)size.y / (float)default_size.height);
    struct converted_pos_s datas;
    sfVector2f center_view = sfView_getCenter(self->host->view);

    datas.pos = sfSprite_getPosition(self->sf_sprite);
    datas.pos = (sfVector2f){datas.pos.x - (center_view.x - (1920 / 2)),
        datas.pos.y - (center_view.y - (1080 / 2))};
    datas.sprite_bounds = sfSprite_getGlobalBounds(self->sf_sprite);
    datas.origin = sfSprite_getOrigin(self->sf_sprite);
    datas.scale = sfSprite_getScale(self->sf_sprite);
    datas.scale = (sfVector2f){datas.scale.x * x_a, datas.scale.y * y_a};
    datas.sprite_bounds.width = datas.sprite_bounds.width * x_a;
    datas.sprite_bounds.height = datas.sprite_bounds.height * y_a;
    datas.pos = (sfVector2f){datas.pos.x * x_a, datas.pos.y * y_a};
    return datas;
}

bool sprite_is_mouse_click(sprite *self, sfEvent *event_datas)
{
    struct converted_pos_s datas;

    if (event_datas->type != sfEvtMouseButtonPressed
        && event_datas->type != sfEvtMouseButtonReleased)
        return false;
    datas = get_pos(self);
    if (datas.pos.x - (datas.origin.x * datas.scale.x) >
        (float)event_datas->mouseButton.x ||
        (datas.pos.x + (datas.sprite_bounds.width -
        (datas.origin.x * datas.scale.x))) <
        (float)event_datas->mouseButton.x)
        return false;
    if (datas.pos.y - (datas.origin.y * datas.scale.y) >
        (float)event_datas->mouseButton.y ||
        (datas.pos.y + (datas.sprite_bounds.height -
        (datas.origin.y * datas.scale.y))) <
        (float)event_datas->mouseButton.y)
        return false;
    return true;
}
