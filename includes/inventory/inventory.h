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
    #include <Class/t_text.h>

    #define NBR_ITEMS 4

    typedef enum inventory_item_type_t {
        item,
        object
    } inventory_item_type_e;

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
        inventory_item_type_e type;
        uint16_t max_amount;
        void (*use)(struct inventory_mgr_t *, struct inventory_item_t *);
    } inventory_item_config_s;

    typedef struct item_object_t {
        char *name;
    } item_object_s;

    typedef struct inventory_hud_item_t {
        sprite *button;
        sprite *item;
        text *amount;
    } inventory_hud_item_s;

    typedef struct inventory_hud_t {
        sprite *host;
        int index_item;
        int index_object;
        inventory_hud_item_s items[NBR_ITEMS];
    } inventory_hud_s;

    sprite *new_item_object(scene *scene_datas, sfVector2f pos, float angle,
        char *name);
    void item_object_destroy(sprite *sprite_datas);
    void item_object_interact(sprite *sprite_datas,
        interaction_s *interaction_datas);
    void inventory_use_medic(inventory_mgr_s *mgr, inventory_item_s *item);

    sprite *inventory_hud_init(scene *scene_datas, sfVector2f pos);
    void inventory_hud_move(sprite *sprite_datas, sfVector2f pos);
    void inventory_add_btn_anim(scene *scene_datas, sprite *sprite_datas);
    void inventory_hud_click(sprite *sprite_datas, window *window_datas);
    void inventory_hud_toggle(scene *scene_datas);
    void inventory_hud_event_toggle(sprite *sprite_datas, window *window_datas);
    void inventory_hud_update(sprite *sprite_datas);
#endif //rpg_inventory
