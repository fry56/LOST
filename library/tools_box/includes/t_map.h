/*
** EPITECH PROJECT, 2022
** t_map.h
** File description:
** desc
*/
#ifndef t_map_h
    #define t_map_h

    #include "t_ctype.h"

    typedef struct map_node {
        char *key;
        void *host;
        void *value;
        struct map_node *next;
        struct map_node *prev;
    } t_map_node;

    typedef struct map {
        t_map_node *head;
        t_map_node *tail;
        tsize_t length;
    } t_map;

    #define map_foreach(map, node) \
        for (t_map_node *node = map->head; node; node = node->next)

    t_map *tmap_new(void);
    t_map_node *tmap_get(t_map *map, char *key);
    t_map_node *tmap_add(t_map *map, char *key, void *value);
    bool tmap_remove(t_map *map, char *key);
    t_map_node *tmap_set(t_map *map, char *key, void *value);
#endif //t_map
