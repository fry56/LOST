/*
** EPITECH PROJECT, 2023
** rpg_inventory.h
** File description:
** desc
*/
#ifndef inventory
    #define inventory

    #include <t_ctype.h>
    #include <Class/t_sprite.h>
    #include <interaction.h>

    #define NBR_ITEMS 4

    typedef struct inventory_item_t {
        uint16_t id;
        char *name;
        uint16_t amount;
    } inventory_item_s;

    typedef struct inventory_mgr_t {
        struct survivor_t *host;
        inventory_item_s items[NBR_ITEMS];
        uint64_t timestamp_wait;
    } inventory_mgr_s;

    typedef struct inventory_item_config_t {
        char *name;
        char *path;
        uint16_t max_amount;
        void (*use)(struct inventory_mgr_t *, struct inventory_item_t *);
    } inventory_item_config_s;

    typedef struct item_object_t {
        char *name;
    } item_object_s;

    sprite *new_item_object(scene *scene_datas, sfVector2f pos, float angle,
        char *name);
    void item_object_destroy(sprite *sprite_datas);
    void item_object_interact(sprite *sprite_datas,
        interaction_s *interaction_datas);

#endif //rpg_inventory
