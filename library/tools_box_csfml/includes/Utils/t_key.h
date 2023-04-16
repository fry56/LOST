/*
** EPITECH PROJECT, 2023
** t_key.h
** File description:
** desc
*/
#ifndef t_key
    #define t_key

    #include <SFML/Window/Event.h>
    #include <t_ctype.h>

    typedef struct key_bind {
        sfKeyCode key;
        bool is_press;
        tsize_t timestamp;
    } key_bind;

#endif //t_key
