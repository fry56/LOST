/*
** EPITECH PROJECT, 2023
** init_notification.c
** File description:
** desc
*/

#include <Class/t_text.h>
#include <notifications.h>

void check_notification_timestamp(scene *scene_datas, sfClock *clock)
{
    uint64_t timestamp = sfClock_getElapsedTime(clock).microseconds;

    list_foreach(scene_datas->list_texts, node) {
        if (!text_have_flag(node->value, "notification"))
            continue;
        if (timestamp > *(uint64_t *)(((text *)node->value)->datas))
            text_destroy(node->value);
    }
}

void notification_init(scene *scene_datas)
{
    scene_add_clock_update_function(scene_datas, check_notification_timestamp);
}
