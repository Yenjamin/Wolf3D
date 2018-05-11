NAME = wolf3d

SRC = main.c \
	reader.c \
	initialize.c \
	raycasting.c \
	draw.c \
	movements.c \

FLAGS = -Wall -Werror -Wextra -g

LIBFT = -L ./libft -lft

INCLUDE = -I wolf3d.h

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	gcc -o $(NAME) $(SRC) $(LIBFT) -lSDL2 -I ~/.brew/include -L ~/.brew/lib

clean:
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all