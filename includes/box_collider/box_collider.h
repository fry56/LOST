/*
** EPITECH PROJECT, 2023
** box_colider.h
** File description:
** desc
*/
#ifndef box_collider_h
    #define box_collider_h

    #include <Class/t_sprite.h>

    typedef struct box_collider_type_t {
        sfIntRect collider_rect;
    } box_collider_type_s;

    typedef struct box_collider_t {
        struct box_colliders_manager_t *box_colliders_mgr;
        sprite *host;
        sfIntRect box;
        bool blocking;
        void *datas;
        uint8_t nbr_zone;
        t_list *current_zone[4];
        t_list *list_sprite_inside;
        t_list_node *node_current_zone[4];
        void (*on_enter)(sprite *sprite_datas, struct box_collider_t *);
        void (*on_exit)(sprite *sprite_datas, struct box_collider_t *);
    } box_collider_s;

    typedef struct box_collider_config_t {
        uint16_t nbr_collisions;
        sfIntRect box[2];
    } box_collider_config_s;

#endif //box_colider
