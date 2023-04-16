/*
** EPITECH PROJECT, 2023
** pathfinding.h
** File description:
** desc
*/
#ifndef pathfinding
    #define pathfinding

    #include <t_ctype.h>
    #include <t_list.h>
    #include <Class/t_sprite.h>

    typedef struct pathfinding_node_t {
        uint32_t id;
        struct pathfinding_manager_t *host;
        sfVector2f pos;
        bool is_blocking;
        uint16_t nbr_child;
        t_list *list_zone;
        struct pathfinding_node_t *child_node[8];
    } pathfinding_node_s;

    typedef struct pathfinding_entity_node_t {
        uint32_t id;
        pathfinding_node_s *node;
        struct pathfinding_entity_node_t *parent_node;
        uint32_t g;
        uint32_t h;
        uint32_t f;
    } pathfinding_entity_node_s;

    typedef struct pathfinding_entity_t {
        sprite *host;
        pathfinding_node_s *current;
        pathfinding_entity_node_s **nodes;
        t_list *list_open;
        t_list *list_close;
        t_list *list_path;
        pathfinding_node_s *target;
    } pathfinding_entity_s;

    typedef struct pathfinding_manager_t {
        struct map_t *host;
        uint32_t width;
        uint32_t height;
        sfVector2u size;
        pathfinding_node_s **nodes;
    } pathfinding_manager_s;

    void pathfinding_update_entity(pathfinding_entity_s *entity);

#endif //pathfinding
