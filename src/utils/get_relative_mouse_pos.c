/*
** EPITECH PROJECT, 2023
** get_relative_mouse_pos.c
** File description:
** desc
*/

#include <survivor/survivor.h>

sfVector2f get_relative_mouse_pos(survivor_s *survivor_datas)
{
    sfView *view = survivor_datas->host->host->view;
    sfVector2f view_pos = sfView_getCenter(view);
    sfVideoMode size = survivor_datas->host->host->host->mode;

    return (sfVector2f){
        view_pos.x - (float)(size.width / 2) + survivor_datas->mouse_pos.x,
        view_pos.y - (float)(size.height / 2) + survivor_datas->mouse_pos.y,
    };
}
