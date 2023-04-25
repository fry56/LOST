/*
** EPITECH PROJECT, 2023
** inventory_iitems_config.h
** File description:
** desc
*/

#ifndef inventory_items_config_h
    #define inventory_items_config_h

    #include "inventory.h"

    static inventory_item_config_s inventory_items_config[] UNUSED = {
        {
            "Alcohol",
            "assets/sprites/items/items/item_alcohol.png",
            item,
            10,
            NULL
        },
        {
            "Fabric",
            "assets/sprites/items/items/item_fabrics.png",
            item,
            10,
            NULL
        },
        {
            "Medic",
            "assets/sprites/items/items/item_medikit.png",
            object,
            3,
            inventory_use_medic
        },
        {
            NULL,
            NULL,
            item,
            0,
            NULL
        }
    };

#endif
