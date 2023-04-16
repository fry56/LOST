
# Tools Box CSFML

Tools box CSFML is a powerfull lib for make graphical app with the [CSFML](https://26.customprotocol.com/csfml/) lib more simply.

Made by Philip J.Fry#2883 with ❤️


## Installation

For use tools_box_csfml lib in your project you need to :
```
- Create directory library at the root of your project
- clone the csfml lib "git clone git@github.com:fry56/tools_box_csfml.git"
- clone the tools_box lib "git clone git@github.com:fry56/tools_box.git"
- create makefile with the template below
```

```Makefile
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = \

OBJ = $(SRC:.c=.o)

INCLUDE_FLAGS = \
	-I include\
	-I library/tools_box/include\
	-I library/tools_box_csfml/include

C_WARNING_FLAGS = -Wextra -Wall
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

# Library
LIB_FLAGS = \
	-lcsfml-graphics -lcsfml-window -lcsfml-system\
	-L library/tools_box_csfml -l:tools_box_csfml.a\
	-L library/tools_box -l:tools_box.a

NAME = my_hunter

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

```

You can now build your project with the commande make.
    
## Documentation

#### Introduction of concept :
- [T_List](https://github.com/fry56/tools_box_csfml/blob/main/README_T_LIST.md)
- [T_Map](https://github.com/fry56/tools_box_csfml/blob/main/README_T_MAP.md)
- [POO in c](https://github.com/fry56/tools_box_csfml/blob/main/README_POO.md)
- [Flag for Sprite / Text](https://github.com/fry56/tools_box_csfml/blob/main/README_FLAG.md)

#### Lib function and explain : 
- [Window](https://github.com/fry56/tools_box_csfml/tree/main/src/window)
- [Scene](https://github.com/fry56/tools_box_csfml/tree/main/src/scene)
- [Sprite](https://github.com/fry56/tools_box_csfml/tree/main/src/sprite)
    - [Animator](https://github.com/fry56/tools_box_csfml/tree/main/src/sprite/animator)
    - [Animation](https://github.com/fry56/tools_box_csfml/tree/main/src/sprite/animation)
    - [Events](https://github.com/fry56/tools_box_csfml/tree/main/src/sprite/events)
- [Text](https://github.com/fry56/tools_box_csfml/tree/main/src/text)

#### Application exemple :