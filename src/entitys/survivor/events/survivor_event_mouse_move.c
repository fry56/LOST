/*
** EPITECH PROJECT, 2023
** view_direction.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sprite.h"
#include "utils.h"
#include "survivor/survivor.h"

void survivor_event_mouse_move(sprite *sprite_datas, window *window_datas)
{
    sfVector2f player_pos;
    sfVector2f mouse_pos;
    survivor_s *survivor_datas = sprite_datas->datas;

    if (window_datas->event.type != sfEvtMouseMoved)
        return;
    if (((survivor_s *)sprite_datas->datas)->freeze)
        return;
    mouse_pos = (sfVector2f){(float)window_datas->event.mouseMove.x,
        (float)window_datas->event.mouseMove.y};
    ((survivor_s *)sprite_datas->datas)->mouse_pos = mouse_pos;
    player_pos = sfSprite_getPosition(sprite_datas->sf_sprite);
    survivor_datas->angle = get_angle_from_coordinate(player_pos,
        get_relative_mouse_pos(survivor_datas));
    sfSprite_setRotation(sprite_datas->sf_sprite, survivor_datas->angle + 90);
}
