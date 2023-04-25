/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** desc
*/

#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_hashmap.h"
#include <t_string.h>
#include <t_printf.h>

void init_scenes(window *window_datas)
{
    scene *main_menu = new_scene(window_datas, "main_menu", NULL, NULL);
    scene *settings_menu = new_scene(window_datas, "settings_menu", NULL, NULL);
    scene *pause_menu = new_scene(window_datas, "pause_menu", NULL, NULL);
    scene *commands = new_scene(window_datas, "commands", NULL, NULL);
    scene *skill_tree = new_scene(window_datas, "skill_tree", NULL, NULL);

    thashmap_add(window_datas->map_datas, "prev_scene", "game");
    scene_add_event_update_function(settings_menu, return_to_main_menu);
    scene_add_event_update_function(pause_menu, pause_to_game);
    scene_add_event_update_function(commands, return_to_settings);
    init_main_menu(main_menu);
    init_settings_menu(settings_menu);
    init_pause_menu(pause_menu);
    init_commands(commands);
    init_skill_tree(skill_tree);
}

void print_info(void)
{
    tprintf("Bonjour survivant, le monde est plongé dans le chaos. Dans"
        " champignons ont muté et se sont transformés en parasites pouvant"
        " infecter les humains. Tu devras survivre dans ce monde"
        " rempli d'hostilités.\n\n"
        "Afin de démarrer le programme, vous n'aurez qu'à exécuter la"
        " commande \"./my_rpg\" qui lancera directement le jeu.\n"
        "Pour vous déplacer vous pourrez utiliser la touche Z pour avancer,"
        "la touche S pour reculer, la touche D pour aller vers la droite.\n"
        "Pour interagir avec des personnages non joueurs tels que des "
        "donneurs de quêtes ou des objets, il faudra appuyer sur la touche F.\n"
        "Vous pourrez recharger vos armes avec la touche R et frapper avec "
        "vos armes grâce à la touche espace.\n Afin de tirer avec les armes,"
        " vous pourrez utiliser le clic gauche de la souris. La mollette "
        "permettra de changer d'arme.\nVous êtes ainsi équipé pour partir "
        "affronter les dangers de ce monde sombre et chaotique.");
}

int main(int argc, char **argv)
{
    window *window_datas = new_window("LOST", (sfVideoMode){1920, 1080, 32});

    if (argc > 1 && argc < 3)
        if (tstr_cmp(argv[1], "-h\0") == 0) {
            print_info();
            return 0;
        }
    if (!check_assets())
        return 84;
    window_datas->global_clock = sfClock_create();
    window_datas->datas = thashmap_new(256);
    sfRenderWindow_setKeyRepeatEnabled(window_datas->window, sfFalse);
    init_loading_screen(window_datas);
    init_scenes(window_datas);
    window_start(window_datas);
    return 0;
}
