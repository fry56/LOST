##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = \
	src/math/int_find_prime_sup.c \
    src/math/int_is_prime.c \
    src/math/int_power.c \
    src/math/double_len.c \
    src/math/int_len.c \
    src/math/int_square.c \
    src/math/double_abs.c \
    src/math/double_modulo.c \
    src/math/int_to_base.c \
    \
    src/mem/calloc.c \
    src/mem/memcpy.c \
    src/mem/memmove.c \
    src/mem/memset.c \
    src/mem/realloc.c \
    src/mem/data_to_binary.c \
    \
    src/print/print_float.c \
	src/print/print_nbr.c \
	src/print/print_nbr_base.c \
	\
    src/printf/tprintf.c \
    src/printf/flags_functions/char.c \
	src/printf/flags_functions/float.c \
	src/printf/flags_functions/int.c \
	src/printf/flags_functions/modulo.c \
	src/printf/flags_functions/string.c \
	\
    src/char/char_is_digit.c \
    src/char/char_is_upper.c \
    src/char/char_lower.c \
    \
	src/string/str_case_lower.c \
	src/string/str_case_upper.c \
	src/string/str_cmp.c \
	src/string/str_cpy.c \
	src/string/str_is_alpha.c \
	src/string/str_is_lower.c \
	src/string/str_is_num.c \
	src/string/str_is_printable.c \
	src/string/str_is_upper.c \
	src/string/str_len.c \
	src/string/str_contain.c \
	src/string/str_rev.c \
	src/string/str_str.c \
	src/string/str_concat.c \
	src/string/str_to_number.c \
	src/string/str_split.c \
	src/string/str_concat_char.c \
	src/string/str_to_binary.c \
	src/string/str_compos.c \
	src/string/str_match.c \
	src/string/str_index_of.c \
	src/string/str_number.c \
	\
	src/write/write.c \
	\
	src/map/map_add.c \
	src/map/map_get.c \
	src/map/map_new.c \
	src/map/map_remove.c \
	src/map/map_set.c \
	\
	src/list/list_add.c \
	src/list/list_get.c \
	src/list/list_new.c \
	src/list/list_remove.c \
	src/list/list_push.c \
	src/list/list_pop.c \
	src/list/list_clear.c \
	src/list/list_print.c \
	\
	src/hashmap/hashmap_new.c \
	src/hashmap/hashmap_get_hash.c \
	src/hashmap/hashmap_add.c \
	src/hashmap/hashmap_get.c \
	src/hashmap/hashmap_remove.c \
	src/hashmap/hashmap_clear.c \
	src/hashmap/hashmap_to_list.c \
	src/hashmap/hashmap_free.c \
	src/hashmap/hashmap_foreach.c \
	\
	src/path/path_is_valide.c \
	src/path/path_open_file.c \
	src/path/path_close_file.c \
	src/path/path_open_dir.c \
	src/path/path_close_dir.c \
	src/path/path_file_content_to_array.c \
	\
	src/xml/xml_get_attribute.c \
	src/xml/xml_get_balise.c \
	src/xml/xml_get_content.c \
	\
	src/assert/assert.c \
	\
	src/xml_token/xml_load.c \
	src/xml_token/xml_free.c \
	src/xml_token/xml_node.c \
	src/xml_token/xml_parser.c \
	src/xml_token/xml_function.c \
	src/xml_token/xml_get.c \

OBJ = $(SRC:.c=.o)

GCC = gcc

INCLUDE_FLAGS = \
	-I includes

C_WARNING_FLAGS = -Wextra -Wall -g
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: tools_box.a
.PHONY : all

tools_box.a: $(OBJ)
	@ar rc $@ $(OBJ)
.PHONY : tools_box.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean

re: clean all
.PHONY: re
