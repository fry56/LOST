/*
** EPITECH PROJECT, 2023
** rpg_utils.h
** File description:
** desc
*/
#ifndef rpg_utils
    #define rpg_utils

    #include <Class/t_sprite.h>
    #include <craft/craft_config.h>
    #include <inventory/inventory_items_config.h>
    #include <t_xml_token.h>
    #include <survivor/survivor.h>
    #include <map/map.h>

    static const unsigned FLIPPED_HORIZONTALLY_FLAG UNUSED = 0x80000000;
    static const unsigned FLIPPED_VERTICALLY_FLAG UNUSED = 0x40000000;
    static const unsigned FLIPPED_DIAGONALLY_FLAG UNUSED = 0x20000000;

    float get_angle_from_coordinate(sfVector2f point_a, sfVector2f point_b);
    sfVector2f get_angle_offset(sfVector2f start, sfVector2f end);
    float get_distance(sfVector2f start, sfVector2f end);
    inventory_item_config_s *get_item_by_name(char *name);
    craft_receipts_s *get_craft_by_name(char *name);
    sfVector2f get_xml_pos(t_xml_node *parent, char *node_name);
    sfImage *image_flip_diagonally(sfImage *source);
    sfVector2f get_relative_mouse_pos(survivor_s *survivor_datas);
    map_tileset_index_s *get_tileset(map_s *map_datas, long id);
    void flip_image(sfImage *tiled_img, bool horizontally,
        bool vertically);
    pathfinding_node_s *get_pathfinding_node_by_pos(pathfinding_manager_s *mgr,
        sfVector2f pos);
    void canva_update(scene *scene_datas, sfVector2f offset);
#endif //rpg_utils
