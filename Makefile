##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = 	src/main.c \
		\
		src/assets/check_assets.c \
		\
		src/utils/get_angle_from_coordinate.c\
		src/utils/get_angle_offset.c \
		src/utils/get_distance.c \
		src/utils/get_item_by_name.c \
		src/utils/get_craft_by_name.c \
		src/utils/get_map_by_name.c \
		src/utils/get_xml_pos.c \
		src/utils/image_flip_diagonally.c \
		src/utils/get_relative_mouse_pos.c \
		src/utils/flip_image.c \
		src/utils/get_tileset.c \
		src/utils/get_pathfinding_node_by_pos.c \
		\
		src/entitys_sounds/get_random_sound_by_type.c \
		\
		src/entitys_animations/entitys_load_animations.c \
		\
		src/entitys/survivor/animator/get_animation_by_type.c \
		\
		src/main_menu/new_game_button.c \
		src/main_menu/continue_button.c \
		src/main_menu/quit_button.c \
		src/main_menu/init_main_menu.c \
		src/main_menu/commands_button.c \
		\
		src/settings/settings_menu.c \
		src/settings/settings_button.c \
		src/settings/settings_button_pause.c \
		src/settings/button_1920x1080.c \
		src/settings/button_1600x900.c \
		src/settings/full_screen.c \
		src/settings/windowed.c \
		src/settings/plus_sound.c \
		src/settings/minus_sound.c \
		src/settings/plus_music.c \
		src/settings/minus_music.c \
		\
		src/pause_menu/pause.c \
		src/pause_menu/quit_game.c \
		src/pause_menu/skill_tree_button.c \
		src/pause_menu/save_button.c \
		src/pause_menu/load_button.c \
		\
		src/skill_tree/skill_tree_update.c \
		src/skill_tree/skill_tree_button.c \
    	\
		src/entitys/survivor/init/survivor_init.c \
		src/entitys/survivor/init/survivor_init_datas.c \
		src/entitys/survivor/init/survivor_init_inventory_mgr.c \
		src/entitys/survivor/init/survivor_init_sound_mgr.c \
		src/entitys/survivor/init/survivor_init_weapon_mgr.c \
		src/entitys/survivor/init/survivor_init_animations.c \
		\
		src/entitys/survivor/survivor_destroy.c \
		src/entitys/survivor/survivor_move.c \
		src/entitys/survivor/survivor_set_pos.c \
		src/entitys/survivor/survivor_damage.c \
		src/entitys/survivor/survivor_update_map.c \
		src/entitys/survivor/survivor_save.c \
		\
		src/entitys/survivor/weapons/weapon_change.c \
		src/entitys/survivor/weapons/weapon_reload.c \
		src/entitys/survivor/weapons/weapon_shoot.c \
		src/entitys/survivor/weapons/weapon_melee.c \
		src/entitys/survivor/weapons/weapon_add_ammos.c \
		src/entitys/survivor/weapons/weapon_set.c \
		\
		src/entitys/survivor/loader/survivor_load_animations.c \
		src/entitys/survivor/loader/survivor_load_sounds.c \
		\
		src/entitys/survivor/events/survivor_event_interactions.c \
		src/entitys/survivor/events/survivor_event_mouse_click.c \
		src/entitys/survivor/events/survivor_event_mouse_move.c \
		src/entitys/survivor/events/survivor_event_movements.c \
		src/entitys/survivor/events/survivor_event_weapon_reload.c \
		src/entitys/survivor/events/survivor_event_space.c \
		\
		src/entitys/objects/weapons/new_weapon_object.c \
		src/entitys/objects/weapons/weapon_object_interact.c \
		src/entitys/objects/weapons/weapon_object_destroy.c \
		\
		src/entitys/objects/ammos/ammos_object_destroy.c \
		src/entitys/objects/ammos/ammos_object_interact.c \
		src/entitys/objects/ammos/new_ammos_object.c \
		\
		src/entitys/objects/items/item_object_destroy.c \
		src/entitys/objects/items/item_object_interact.c \
		src/entitys/objects/items/new_item_object.c \
		\
		src/hud/notifications/notification_init.c \
		src/hud/notifications/new_notification.c \
		\
		src/hud/weapon/weapon_hud_init.c \
		src/hud/weapon/weapon_hud_update.c \
		src/hud/weapon/weapon_hud_move.c \
		\
		src/raycast/raycast.c \
		src/raycast/raycast_nearest_sprite_by_flag.c \
		\
		src/entitys/zombie/init/zombie_init.c \
		src/entitys/zombie/init/zombie_init_animations.c \
		src/entitys/zombie/init/zombie_init_sound_mgr.c \
		src/entitys/zombie/init/zombie_init_pathfinding.c \
		\
		src/entitys/zombie/loader/zombie_load_animations.c \
		src/entitys/zombie/loader/zombie_load_sounds.c \
		\
		src/entitys/zombie/zombie_destroy.c \
		src/entitys/zombie/zombie_move.c \
		src/entitys/zombie/zombie_set_pos.c \
		src/entitys/zombie/zombie_damage.c \
		src/entitys/zombie/zombie_set_trigger.c \
		\
		src/entitys/zombie/events/zombie_event_move.c \
		src/entitys/zombie/events/zombie_event_attack.c \
		\
		src/entitys/zombie/animator/get_zombie_anim_by_type.c \
		\
		src/inventory/inventory_add_item.c \
		src/inventory/inventory_have_item.c \
		src/inventory/inventory_remove_item.c \
		src/inventory/inventory_set_item.c \
		src/inventory/inventory_use_item.c \
		src/inventory/inventory_get_item_by_name.c \
		\
		src/inventory/use/inventory_use_medic.c \
		\
		src/craft/craft_new_object.c \
		\
		src/particles/new_particles.c \
		src/particles/loader/particles_load_animations.c \
		\
		src/map/init_map.c \
		src/map/init_scene.c \
		src/map/init_collisions.c \
		src/map/init_npc.c \
		src/map/loader/map_load_tileset.c \
		src/map/loader/map_load.c \
		src/map/loader/map_load_tiled.c \
		src/map/init_go_to.c \
		src/map/loader/map_entity_load.c \
		\
		src/box_collider/box_colliders_manager/init_box_colliders_manager.c\
		\
		src/box_collider/get_zone_by_pos.c \
		src/box_collider/update_zone_of_box_collider.c \
		src/box_collider/box_collider_set_pos.c\
		src/box_collider/new_box_collider.c \
		src/box_collider/get_valide_offset.c \
		src/box_collider/is_collide.c \
		src/box_collider/box_collider_destroy.c \
		\
		src/pathfinding/init_pathfinding_manager.c \
		src/pathfinding/pathfinding_update_entity.c \
		\
		src/canva/canva_update.c \
		\
		src/loading_screen/init_loading_screen.c \
		\
		src/entitys/npc/init/npc_init.c \
		src/entitys/npc/loader/npc_load_animations.c \
		src/entitys/npc/events/npc_event_interactions.c \
		src/entitys/npc/events/npc_event_next_dialogue.c \
		\
		src/skill_tree/init_skill_tree.c \
		\
		src/hud/inventory/inventory_hud_init.c \
		src/hud/inventory/inventory_hud_move.c \
		src/hud/inventory/inventory_hud_update.c \
		src/hud/inventory/inventory_hud_new_object.c \
		src/hud/inventory/inventory_add_btn_anim.c \
		src/hud/inventory/inventory_hud_event.c \
		src/inventory/inventory_toggle.c \
		\
		src/quest/init_special_medkit.c \
		src/quest/special_medkit_object_destroy.c \
		src/quest/special_medkit_object_interact.c \

OBJ = $(SRC:.c=.o)

INCLUDE_FLAGS = \
	-I includes\
	-I library/tools_box/includes\
	-I library/tools_box_csfml/includes

C_WARNING_FLAGS = -Wextra -Wall -g
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

# Library
LIB_FLAGS = \
	-lm \
	-L library/tools_box_csfml -l:tools_box_csfml.a \
	-L library/tools_box -l:tools_box.a \
	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \

NAME = my_rpg

GCC = gcc

all: $(NAME)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

$(NAME): tools_box tools_box_csfml $(OBJ)
	@$(GCC) -o $@ $(OBJ) $(INCLUDE_FLAGS) $(LIB_FLAGS)
.PHONY: $(NAME)

clean:
	@rm -f $(OBJ)
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

### Library ###
tools_box:
	make -C library/tools_box

tools_box_csfml:
	make -C library/tools_box_csfml
