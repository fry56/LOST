/*
** EPITECH PROJECT, 2023
** survivor_damage.c
** File description:
** desc
*/

#include <survivor/survivor.h>
#include <entity_sounds.h>
#include <map/map.h>
#include <zombie/zombie.h>

void survivor_death_restart_game(sprite *sprite_datas, sfClock *clock)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    sprite *jovan;

    if (!survivor_datas->death)
        return;
    if (survivor_datas->timestamp_interaction >
        (uint64_t)sfClock_getElapsedTime(clock).microseconds)
        return;
    jovan = sprite_get_by_flag(sprite_datas->host, "death_ui");
    survivor_datas->health = (100 + (survivor_datas->health_level * 25));
    survivor_datas->freeze = false;
    survivor_datas->death = false;
    sprite_move(sprite_datas, (sfVector2f){
        survivor_datas->temp_datas->spawn_pos.x - sprite_datas->pos.x,
        survivor_datas->temp_datas->spawn_pos.y - sprite_datas->pos.y
    });
    sprite_destroy(jovan);
}

static void init_death_ui(sprite *sprite_datas)
{
    sprite *jovan = new_sprite(sprite_datas->host,
        "assets/sprites/death_image.png", 50);
    sprite_add_flag(jovan, "death_ui");
    sprite_set_pos(jovan, sfView_getCenter(sprite_datas->host->view));
    sfSprite_setScale(jovan->sf_sprite, (sfVector2f){0.3f, 0.3f});
}

static void set_zombie_idle(sprite *sprite_datas)
{
    sprite *temp_sprite;

    list_foreach(sprite_datas->host->list_sprites, node) {
        temp_sprite = node->value;
        if (!sprite_have_flag(temp_sprite, "zombie"))
            continue;
        zombie_set_idle(temp_sprite);
    }
}

void survivor_damage(sprite *sprite_datas, uint32_t amount)
{
    survivor_s *survivor_datas = sprite_datas->datas;

    if (survivor_datas->death)
        return;
    survivor_datas->health -= (int)amount;
    if (survivor_datas->health > 0) {
        sound_manager_play_sound(survivor_datas->sound_mgr,
            "sound_survivor_hurt_1");
    } else {
        survivor_datas->freeze = true;
        survivor_datas->death = true;
        sound_manager_play_sound(survivor_datas->sound_mgr,
            "sound_survivor_death");
        survivor_datas->timestamp_interaction = sfClock_getElapsedTime(
            sprite_datas->host->host->global_clock).microseconds + 4000000;
        init_death_ui(sprite_datas);
        set_zombie_idle(sprite_datas);
    }
}
