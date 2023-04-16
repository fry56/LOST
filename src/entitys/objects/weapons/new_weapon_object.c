/*
** EPITECH PROJECT, 2023
** new_weapon_object.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/weapon/weapon_config.h>
#include <t_assert.h>
#include <t_mem.h>
#include <interaction.h>
#include <math.h>
#include <survivor/survivor.h>

sprite *new_weapon_object(scene *scene_datas, sfVector2f pos, float angle,
    weapons_type_e type)
{
    weapon_config_s weapon = weapons_config[type];
    sprite *object = new_sprite(scene_datas, weapon.weapon_path, 10);
    interaction_s *object_interaction;
    weapon_object_s *weapon_object;

    sprite_set_pos(object, pos);
    sprite_add_flag(object, "interactive");
    sfSprite_setRotation(object->sf_sprite, angle);
    tassert((object_interaction = tcalloc(1, sizeof(interaction_s))) == NULL);
    tassert((weapon_object = tcalloc(1, sizeof(weapon_object_s))) == NULL);
    object->datas = object_interaction;
    object->destroy = weapon_object_destroy;
    object_interaction->host = object;
    object_interaction->datas = weapon_object;
    object_interaction->interaction_dist = 100;
    object_interaction->onInteract = weapon_object_interact;
    weapon_object->type = type;
    weapon_object->loaded_ammos = (rand() % weapon.magazin_size);
    return object;
}
