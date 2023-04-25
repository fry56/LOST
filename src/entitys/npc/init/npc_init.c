/*
** EPITECH PROJECT, 2023
** npc_init.c
** File description:
** desc
*/

#include "npc/npc.h"
#include "Class/t_sprite.h"
#include <t_mem.h>
#include <map/map.h>

static void init_interaction(sprite *npc_sprite)
{
    interaction_s *interact = tcalloc(1, sizeof(interaction_s));

    npc_sprite->datas = interact;
    interact->interaction_dist = 150;
    interact->host = npc_sprite;
    interact->onInteract = npc_envent_interactions;
    sprite_add_flag(npc_sprite, "interactive");
}

sprite *npc_init(scene *scene_datas, npc_config_s *config)
{
    sprite *npc_sprite = new_sprite(scene_datas, NULL, 20);
    animator *npc_animator = new_animator(npc_sprite);
    npc_s *npc_datas = tcalloc(1, sizeof(npc_s));

    animator_add_animation(npc_animator, thashmap_get(scene_datas->
        host->map_datas, "anim_npc_idle")->value);
    animator_play_animation(npc_animator, "anim_npc_idle");
    sprite_set_pos(npc_sprite, config->pos);
    sfSprite_setScale(npc_sprite->sf_sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setRotation(npc_sprite->sf_sprite, config->angle);
    init_interaction(npc_sprite);
    sprite_add_flag(npc_sprite, "npc");
    ((interaction_s *)npc_sprite->datas)->datas = npc_datas;
    npc_datas->box_collider = new_box_collider(((map_s *)scene_datas->datas)->
        box_colliders_mgr,
        (sfIntRect){(int)config->pos.x, (int)config->pos.y, 50, 50}, true);
    npc_datas->box_collider->host = npc_sprite;
    npc_datas->config = config;
    return npc_sprite;
}
