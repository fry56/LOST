/*
** EPITECH PROJECT, 2023
** new_ammos_object.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/weapon/weapon_config.h>
#include <t_assert.h>
#include <t_mem.h>
#include <interaction.h>
#include <survivor/survivor.h>

sprite *new_ammos_object(scene *scene_datas, sfVector2f pos, float angle,
    weapons_type_e type)
{
    weapon_config_s weapon = weapons_config[type];
    sprite *object = new_sprite(scene_datas, weapon.ammo_path, 10);
    interaction_s *object_interaction;
    ammos_object_s *ammos_object;

    sprite_set_pos(object, pos);
    sprite_add_flag(object, "interactive");
    sfSprite_setRotation(object->sf_sprite, angle);
    tassert((object_interaction = tcalloc(1, sizeof(interaction_s))) == NULL);
    tassert((ammos_object = tcalloc(1, sizeof(ammos_object_s))) == NULL);
    object->datas = object_interaction;
    object->destroy = ammos_object_destroy;
    object_interaction->host = object;
    object_interaction->datas = ammos_object;
    object_interaction->interaction_dist = 100;
    object_interaction->onInteract = ammos_object_interact;
    ammos_object->type = type;
    return object;
}
