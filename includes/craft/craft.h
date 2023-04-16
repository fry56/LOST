/*
** EPITECH PROJECT, 2023
** craft.h
** File description:
** desc
*/
#ifndef craft
    #define craft

    #include <t_ctype.h>
    #include <Class/t_sprite.h>

    typedef struct craft_receipts_item_require_t {
        uint16_t amount;
        char *name;
    }craft_receipts_item_require_s;

    typedef struct craft_receipts_t {
        char *new_object_name;
        uint16_t amount;
        uint16_t nbr_required_item;
        craft_receipts_item_require_s items_require[2];
    } craft_receipts_s;

    bool craft_new_object(sprite *sprite_datas, char *new_object_name);
#endif //craft
