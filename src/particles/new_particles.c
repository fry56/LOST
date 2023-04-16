/*
** EPITECH PROJECT, 2023
** new_particles.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>

sprite *new_particles(scene *scene_datas, sfVector2f pos,
    animation *anim)
{
    sprite *new_particles = new_sprite(scene_datas, NULL, 19);

    new_animator(new_particles);
    animator_add_animation(new_particles->animator, anim);
    animator_add_callback(new_particles->animator, anim->name, sprite_destroy);
    sprite_set_pos(new_particles, pos);
    animator_play_animation(new_particles->animator, anim->name);
    sfSprite_rotate(new_particles->sf_sprite, rand() % 360);
    sfSprite_setScale(new_particles->sf_sprite, (sfVector2f){1.5f, 1.5f});
    return new_particles;
}
