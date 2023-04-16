/*
** EPITECH PROJECT, 2023
** assets_checker.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_path.h>
#include <paths.h>
#include <t_printf.h>
#include <t_xml_token.h>

bool check_assets(void)
{
    t_xml *doc = t_xml_load(assets_config_path);

    if (doc == NULL)
        return false;
    list_foreach(doc->root->list_children, node) {
        if (!tpath_is_valide(((t_xml_node *)node->value)->inner_text)) {
            tprintf("Assets %s missing !\n",
                ((t_xml_node *)node->value)->inner_text);
            return false;
        }
    }
    t_xml_free(doc);
    return true;
}
