/*
** EPITECH PROJECT, 2022
** t_class_window.h
** File description:
** desc
*/
#ifndef t_class_window
    #define t_class_window

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <t_list.h>
    #include <t_hashmap.h>
    #include <Utils/t_key.h>

    typedef struct garbage {
        t_list_node *node;
        void (*destroy)(void *datas);
    } garbage;

    typedef struct window {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;

        t_hashmap *map_datas;
        t_hashmap *map_scenes;
        t_hashmap_node *actual_scene;
        t_list *list_node_garbage;
        void *datas;
        sfClock *global_clock;
        long long last_tick;
        float deltatime;
    } window;

    bool window_change_scene(window *self, char *scene_name);
    window *new_window(char *name, sfVideoMode mode);
    void window_clock_update(window *window_datas);
    void window_event_update(window *window_datas);
    void window_destroy(window *self);
    int window_start(window *self);
    void window_add_garbage(window *window_datas, t_list_node *node,
        void (*destroy)(void *datas));
#endif //t_class_window
