/*
** EPITECH PROJECT, 2023
** init_notification.c
** File description:
** desc
*/

#include "Class/t_text.h"
#include "notifications.h"

void check_notification_timestamp(scene *scene_datas, sfClock *clock)
{
    uint64_t timestamp = sfClock_getElapsedTime(clock).microseconds;
    sfVector2f view = sfView_getCenter(scene_datas->view);
    notification_s *temp;

    list_foreach(scene_datas->list_texts, node) {
        if (!text_have_flag(node->value, "notification"))
            continue;
        temp = ((text *)node->value)->datas;
        if (timestamp > temp->timestamp)
            text_destroy(node->value);
        text_set_pos(temp->host, (sfVector2f){view.x, view.y + temp->offset.y});
    }
}

void notification_init(scene *scene_datas)
{
    scene_add_clock_update_function(scene_datas, check_notification_timestamp);
}
