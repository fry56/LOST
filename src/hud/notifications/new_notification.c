/*
** EPITECH PROJECT, 2023
** new_notification.c
** File description:
** desc
*/

#include "Class/t_text.h"
#include "t_mem.h"
#include "notifications.h"

void notification_destroy(text *self)
{
    free(self->datas);
}

static void set_pos(text *notif_text, notification_s *notif_datas)
{
    text_set_pos(notif_text, (sfVector2f){1920 / 2, 1080 - (1080 / 6)});
    notif_datas->offset = (sfVector2f){0, 360};
}

static void update_pos(scene *scene_datas)
{
    notification_s *temp;

    list_foreach(scene_datas->list_texts, node) {
        temp = ((text *)node->value)->datas;
        if (!text_have_flag(node->value, "notification"))
            continue;
        text_move(node->value, (sfVector2f){0, -35});
        temp->offset = (sfVector2f){0, temp->offset.y - 35};
    }
}

text *new_notification(scene *scene_datas, char *content, uint16_t duration)
{
    text *notif_text = new_text(scene_datas, content,
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    notification_s *notif_datas = tcalloc(1, sizeof(notification_s));

    update_pos(scene_datas);
    notif_datas->timestamp = sfClock_getElapsedTime(scene_datas->host->
        global_clock).microseconds + (1000000 * duration);
    notif_text->datas = notif_datas;
    notif_datas->host = notif_text;
    text_add_flag(notif_text, "notification");
    text_set_font_size(notif_text, 16);
    text_set_origin_center(notif_text);
    set_pos(notif_text, notif_datas);
    notif_text->destroy = notification_destroy;
    return notif_text;
}
