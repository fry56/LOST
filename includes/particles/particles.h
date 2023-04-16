/*
** EPITECH PROJECT, 2023
** particles.h
** File description:
** desc
*/
#ifndef particles
    #define particles

    #include <Class/t_sprite.h>

    void particles_load_animations(window *window_datas);
    sprite *new_particles(scene *scene_datas, sfVector2f pos,
        animation *anim);

#endif //particles
