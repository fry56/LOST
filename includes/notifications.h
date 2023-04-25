/*
** EPITECH PROJECT, 2023
** notifications.h
** File description:
** desc
*/
#ifndef notifications
    #define notifications

    #include <Class/t_text.h>

    typedef struct notification_t {
        text *host;
        sfVector2f offset;
        uint64_t timestamp;
    } notification_s;

    text *new_notification(scene *scene_datas, char *content,
        uint16_t duration);
    void notification_init(scene *scene_datas);
#endif //notifications
