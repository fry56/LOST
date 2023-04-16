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
            10,
            NULL
        },
        {
            "Fabric",
            "assets/sprites/items/items/item_fabrics.png",
            10,
            NULL
        },
        {
            "Medic",
            "assets/sprites/items/items/item_medikit.png",
            3,
            NULL
        },
        {
            NULL,
            NULL,
            0,
            NULL
        }
    };

#endif
