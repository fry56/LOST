/*
** EPITECH PROJECT, 2023
** rpg_functions.h
** File description:
** desc
*/
#ifndef rpg_functions
    #define rpg_functions

    #include <t_ctype.h>
    #include <Class/t_sprite.h>

    // ASSETS //
    bool check_assets(void);
    void init_loading_screen(window *window_datas);
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
    void init_1920x1080_button(sprite *button_1920_1080);
    void init_1600x900_button(sprite *button_1600_900);
    void init_fullscreen_button(sprite *button_fullscreen);
    void init_windowed_button(sprite *button_windowed);
    void init_plus_sound_button(sprite *plus_sound);
    void init_minus_sound_button(sprite *minus_sound);
    void init_plus_music_button(sprite *plus_music);
    void init_minus_music_button(sprite *minus_music);
    // PAUSE //
    void init_pause_menu(scene *pause_menu);
    void go_pause_menu(scene *data, window *window_datas);
    void pause_to_game(scene *data, window *window_datas);
    void init_settings_pause_button(sprite *settings_button);
    void init_quit_pause_button(sprite *quit_button);
    // SKILL_TREE //
    void init_skill_tree(scene *scene_datas);
    void init_skill_tree_pause_button(sprite *quit_button);
    void skill_tree_update(scene *scene_datas);
    void init_button_skill_tree(scene *scene_datas);
    void init_save_pause_button(sprite *quit_button);
    void init_load_pause_button(sprite *quit_button);
#endif //rpg_functions
