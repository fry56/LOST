/*
** EPITECH PROJECT, 2023
** npc.h
** File description:
** desc
*/
#ifndef npc
    #define npc

    #include <Class/t_sprite.h>
    #include <interaction.h>
    #include <npc/npc_animations_config.h>
    #include <box_collider/box_collider.h>

    typedef struct npc_config_dialogue_t {
        uint16_t dialogue_step;
        uint16_t nbr_dialogue_step;
        char **anwser;
    } npc_config_dialogue_s;

    typedef struct npc_config_t {
        sfVector2f pos;
        float angle;
        uint32_t status;
        uint16_t nbr_dialogue;
        npc_config_dialogue_s **dialogue;
    } npc_config_s;

    typedef struct npc_t {
        sprite *host;
        npc_config_s *config;
        box_collider_s *box_collider;
    } npc_s;

    sprite *npc_init(scene *scene_datas, npc_config_s *config);
    void npc_load_animations(window *window_datas);
    void npc_envent_interactions(sprite *sprite_datas,
        interaction_s *interaction_data);
    void npc_event_next_dialogue(sprite *sprite_data, npc_s *npc_datas);
#endif //npc
