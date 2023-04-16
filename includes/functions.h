/*
** EPITECH PROJECT, 2023
** rpg_functions.h
** File description:
** desc
*/
#ifndef rpg_functions
    #define rpg_functions

    #include <t_ctype.h>

    // ASSETS //
    bool check_assets(void);
    // SCENES //
    void init_scenes(window *window_datas);
    // MAIN_MENU //
    void init_new_game_button(sprite *new_game);
    void init_continue_button(sprite *continue_button);
    void init_settings_button(sprite *settings_button);
    void init_quit_button(sprite *quit_button);
    void init_main_menu(scene *main_menu);
    void init_commands_button(sprite *commands_button);
    void init_commands(scene *commands);
    void return_to_settings(scene *data, window *window_datas);
    // SETTINGS //
    void init_settings_menu(scene *settings_menu);
    void return_to_main_menu(scene *data, window *window_datas);
    // PAUSE //
    void init_pause_menu(scene *pause_menu);
    void go_pause_menu(scene *data, window *window_datas);
    void pause_to_game(scene *data, window *window_datas);
    void init_settings_pause_button(sprite *settings_button);
    void init_quit_pause_button(sprite *quit_button);
#endif //rpg_functions
