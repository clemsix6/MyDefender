##
## EPITECH PROJECT, 2022
## Minishell1
## File description:
## Makefile
##

CC =	gcc
CFLAGS =	-W -Wextra -Wall -I./include
LDFLAGS =	-lcsfml-window \
			-lcsfml-graphics \
			-lcsfml-system \
			-lcsfml-audio \
			-L./lib/cly \
			-lcly

SRC =	$(wildcard src/*.c)

OBJ =	$(SRC:.c=.o)

BIN_NAME	=	my_defender

all: make_lib $(BIN_NAME) $(OBJ)

make_lib:
	@ make -C lib/cly

$(BIN_NAME): $(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34mMY DEFENDER \033[0m"
	@ $(CC) -o $(BIN_NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	@ rm -f $(OBJ)
	@ make clean -C lib/cly

fclean: clean
	@ rm -f $(BIN_NAME)
	@ make fclean -C lib/cly

re: fclean all