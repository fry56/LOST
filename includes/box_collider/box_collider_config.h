/*
** EPITECH PROJECT, 2023
** box_collider_config.h
** File description:
** desc
*/
#ifndef box_collider_config
    #define box_collider_config

    #include <box_collider/box_collider.h>

    static box_collider_config_s box_colliders_configs[] UNUSED = {
            {
                2,
                {
                    {
                        0,
                        0,
                        64,
                        19
                    },
                    {
                        0,
                        0,
                        19,
                        64
                    }
                }
            },
            {
                1,
                {
                    {
                        0,
                        0,
                        19,
                        64
                    }
                }
            },
            {
                2,
                {
                    {
                        0,
                        90,
                        64,
                        19
                    },
                    {
                        0,
                        0,
                        19,
                        64
                    }
                }
            },
            {
                1,
                {
                    {
                        0,
                        90,
                        64,
                        19
                    }
                }
            },
            {
                1,
                {
                    {
                        0,
                        0,
                        64,
                        19
                    }
                }
            },
            {
                2,
                {
                    {
                        0,
                        0,
                        64,
                        19
                    },
                    {
                        90,
                        0,
                        19,
                        64
                    }
                }
            },
            {
                1,
                {
                    {
                        90,
                        0,
                        19,
                        64
                    }
                }
            },
            {
                2,
                {
                    {
                        90,
                        0,
                        19,
                        64
                    },
                    {
                        0,
                        90,
                        64,
                        19
                    }
                }
            },
            {
                1,
                {
                    {
                        0,
                        0,
                        64,
                        64
                    }
                }
            },
            {
                1,
                {
                    {
                        32,
                        32,
                        32,
                        32
                    }
                }
            }
    };

#endif //box_collider_config