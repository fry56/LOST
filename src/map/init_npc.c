/*
** EPITECH PROJECT, 2023
** init_npc.c
** File description:
** desc
*/

#include <map/map.h>
#include <utils.h>
#include <t_string.h>
#include <npc/npc.h>
#include <t_mem.h>

static void init_dialogue(t_xml_node *temp_npc, npc_config_s *temp_config)
{
    int dialogue = 0, anwser, nbr_step;
    t_xml_node *dialogue_node, *anwser_node;

    temp_config->nbr_dialogue = temp_npc->list_children->length;
    temp_config->dialogue = tcalloc(1, temp_npc->list_children->length * 8);
    list_foreach(temp_npc->list_children, node_parent) {
        anwser = 0;
        dialogue_node = node_parent->value;
        nbr_step = (int)dialogue_node->list_children->length;
        temp_config->dialogue[dialogue] =
            tcalloc(1, sizeof(npc_config_dialogue_s));
        temp_config->dialogue[dialogue]->anwser =
            tcalloc(dialogue_node->list_children->length, sizeof(char *));
        list_foreach(dialogue_node->list_children, node_cildren) {
            anwser_node = node_cildren->value;
            temp_config->dialogue[dialogue]->anwser[anwser++] =
                tstr_cpy(NULL, anwser_node->inner_text);
        }
        temp_config->dialogue[dialogue++]->nbr_dialogue_step = nbr_step;
    }
}

void init_npc(map_s *temp, t_xml_node *npc_node)
{
    t_xml_node *temp_npc;
    npc_config_s *temp_config;

    if (npc_node == NULL)
        return;
    list_foreach(npc_node->list_children, node) {
        temp_npc = node->value;
        temp_config = tcalloc(1, sizeof(npc_config_s));
        temp_config->pos = get_xml_pos(temp_npc, "pos");
        temp_config->angle = (float)tstr_to_number(
            t_xml_get_node_by_tag(temp_npc, "angle")->inner_text);
        temp_config->status = 0;
        init_dialogue(t_xml_get_node_by_tag(temp_npc, "dialogue_list"),
            temp_config);
        npc_init(temp->host, temp_config);
    }
}
