/*
** EPITECH PROJECT, 2023
** map.h
** File description:
** desc
*/
#ifndef map_h
    #define map_h

    #include <Class/t_sprite.h>
    #include <survivor/weapon/weapon.h>
    #include <box_collider/box_collider.h>
    #include <t_xml_token.h>
    #include <pathfinding/pathfinding.h>

    typedef struct tileset_t {
        char *name;
        sfImage **images;
        uint32_t tile_width;
        uint32_t tile_height;
        uint32_t spacing;
        uint32_t margin;
        uint32_t tile_count;
        uint32_t columns;
        t_hashmap_node *node;
    } tileset_s;

    typedef struct map_tileset_index_t {
        struct map_t *host;
        tileset_s *tileset;
        int start_index;
        int end_index;
    } map_tileset_index_s;

    typedef struct map_layer_t {
        struct map_t *host;
        int id;
        char *name;
        sprite *sprite;
    } map_layer_s;

    typedef struct box_colliders_manager_t {
        uint32_t width;
        uint32_t height;
        t_list **list_zones;
        struct map_t *host;
    } box_colliders_manager_s;

    typedef struct map_t {
        scene *host;
        char *name;
        t_list *list_layer;
        t_list *list_tileset;
        sprite *survivor_entity;
        int width;
        int height;
        int t_width;
        int t_height;
        box_colliders_manager_s *box_colliders_mgr;
        pathfinding_manager_s *pathfinding_mgr;
    } map_s;

    void init_map(map_s *map_datas);
    void map_load(window *window_datas);
    void init_scene(scene *scene_datas, t_xml_node *map_node);
    void map_load_tiled(map_s *map_datas, char *path);
    void map_load_tileset(map_s *map_datas, t_xml_node *root);
    void init_go_to(map_s *temp, t_xml_node *node);
    void init_npc(map_s *temp, t_xml_node *go_to_node);

    void init_box_coliders_manager(map_s *map_datas);
    t_list *get_zone_by_pos(box_colliders_manager_s *mgr, sfVector2f pos);
    void update_zone_of_box_collider(box_colliders_manager_s *mgr,
        box_collider_s *box_collider);
    void box_collider_set_pos(box_collider_s *box_collider, sfVector2f pos);
    box_collider_s *new_box_collider(box_colliders_manager_s *mgr,
        sfIntRect pos, bool blocking);
    sfVector2f get_valide_offset(box_collider_s *self, sfVector2f offset);
    void init_collider_layer(map_s *map_datas, t_xml_node *node);
    bool is_collide(t_list *zone, sfIntRect box);
    void box_collider_destroy(box_collider_s *box_collider);

    void init_pathfinding_manager(map_s *map_datas);
    void map_entity_load( map_s *temp, t_xml_node *map_node);
#endif //map
