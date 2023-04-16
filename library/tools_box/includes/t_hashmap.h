/*
** EPITECH PROJECT, 2023
** t_hashmap.h
** File description:
** desc
*/
#ifndef t_hashmap_h
    #define t_hashmap_h

    #include <t_ctype.h>
    #include <t_list.h>

    typedef struct hashmap_node {
        struct hashmap *host;
        char *key;
        u32 hash;
        void *value;
        struct hashmap_node *parent_node;
        t_list *childs_node;
    } t_hashmap_node;

    typedef struct hashmap {
        u32 size;
        u32 child_elements;
        u32 node_elements;
        t_hashmap_node **map;
    } t_hashmap;

    t_hashmap *thashmap_new(u32 size);
    t_hashmap_node *thashmap_add(t_hashmap *hashmap, char *key, void *value);
    bool thashmap_remove(t_hashmap *hashmap, const char *key);
    t_hashmap_node *thashmap_get(t_hashmap *hashmap, const char *key);
    u32 hashmap_get_hash(u32 size, const char *key);
    void thashmap_clear(t_hashmap *hashmap);
    t_list *thashmap_to_list(t_hashmap *hashmap);
    void thashmap_free(t_hashmap *hashmap);
    void thashmap_foreach(t_hashmap *hashmap
        , void (function)(char *key, void *value));
#endif //t_hashmap
