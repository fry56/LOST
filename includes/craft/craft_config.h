/*
** EPITECH PROJECT, 2023
** craft_config.h
** File description:
** desc
*/
#ifndef craft_config
    #define craft_config

    #include "craft.h"

    static craft_receipts_s craft_receipts_config[] UNUSED = {
            {
                "Medic",
                1,
                2,
                {
                    {
                        1,
                        "Fabric"
                    },
                    {
                        1,
                        "Alcohol"
                    }
                }
            },
            {
                NULL,
                0,
                0,
                {}
            }
    };

#endif //craft_config
