/*
** EPITECH PROJECT, 2023
** new_notification.c
** File description:
** desc
*/

#include <Class/t_text.h>
#include <t_mem.h>
#include <t_assert.h>

void notification_destroy(text *self)
{
    free(self->datas);
}

text *new_notification(scene *scene_datas, char *content, uint16_t duration)
{
    text *notification = new_text(scene_datas, content,
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    uint64_t *timestamp = tcalloc(1, sizeof(uint64_t));

    tassert(timestamp == NULL);
    list_foreach(scene_datas->list_texts, node) {
        if (!text_have_flag(node->value, "notification"))
            continue;
        text_move(node->value, (sfVector2f){0, -35});
    }
    *timestamp = sfClock_getElapsedTime(scene_datas->host->global_clock)
        .microseconds + (1000000 * duration);
    notification->datas = timestamp;
    text_add_flag(notification, "notification");
    text_set_font_size(notification, 16);
    text_set_origin_center(notification);
    text_set_pos(notification, (sfVector2f){1920 / 2, 1080 - (1080 / 6)});
    notification->destroy = notification_destroy;
    return notification;
}
