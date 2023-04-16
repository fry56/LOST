/*
** EPITECH PROJECT, 2023
** xml_function.c
** File description:
** desc
*/

#include <t_xml_token.h>
#include <t_mem.h>
#include <t_assert.h>
#include <t_string.h>

static void get_node_tag_attribute(t_xml_node *node, char *buf)
{
    char *match = tstr_match(buf, " .*=\".*\"");;
    int key_end, attribute_end;
    t_xml_attribute *temp;

    if (match == NULL)
        return;
    while (match++) {
        tassert((temp = tcalloc(1, sizeof(t_xml_attribute))) == NULL);
        key_end = tstr_index_of(match, "=\"");
        temp->key = tstr_ncpy(NULL, match, key_end - 1);
        attribute_end = tstr_index_of(match + key_end + 2, "\"");
        temp->value = tstr_ncpy(NULL, match + key_end + 2, attribute_end - 1);
        tlist_add(node->list_attributes, temp);
        if (*(match + key_end + 2 + attribute_end + 1) == '>')
            return;
        if ((match = tstr_match(match + key_end + attribute_end + 3,
            " .*=\".*\"")) == NULL)
            return;
    }
}

static int get_node_tag(t_xml_node *node, char *buf)
{
    char *match = tstr_match(buf, "<.*>");
    int i = 0;
    int tag_end;

    if (match == NULL)
        return 0;
    get_node_tag_attribute(node, match);
    tag_end = tstr_index_of(match, " ");
    for (; match[i] != '>'; ++i);
    if (tag_end < i && tag_end > 0)
        node->tag = tstr_ncpy(NULL, match + 1, tag_end - 2);
    else
        node->tag = tstr_ncpy(NULL, match + 1, i - 2);
    return i + 1;
}

static int get_node_inner_text(t_xml_node *node, char *buf)
{
    int index = 0;

    for (; buf[index] != '\0'; ++index) {
        if (buf[index] == '<')
            break;
    }
    if (index > 0)
        node->inner_text = tstr_ncpy(NULL, buf, index - 1);
    return index;
}

int t_xml_token_is_valide_end_tag(char *buf, t_xml_node *current, size_t *index)
{
    int temp_len;

    if (buf[*index + 1] == '/') {
        temp_len = tstr_len(current->tag);
        if (tstr_ncmp(current->tag, buf + (*index + 2), temp_len - 1) != 0 ||
            *(buf + (*index + 2 + temp_len)) != '>')
            return 0;
        *index += temp_len;
        return 1;
    }
    return 2;
}

void t_xml_token_add_datas(t_xml *doc, t_xml_node **current,
    size_t *index, char *buf)
{
    if (*current == NULL)
        *current = doc->root;
    else
        *current = t_xml_new_node(*current);
    *index += get_node_tag(*current, buf + *index);
    *index += get_node_inner_text(*current, buf + *index);
    if (is_orphan_tag(buf, *index))
        *current = *&(*current)->parent;
}
