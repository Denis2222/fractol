.PHONY: libft

SRCS = display.c \
	   setup.c \
	   key.c \
	   color.c \
	   main.c

NAME = fractol
GCC_FLAG = -Wall -Werror -Wextra
CC = gcc #$(GCC_FLAG)

OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)
	./fractol 1

libft:
	make -C ./libft/

minilibx:
	make -C ./minilibx/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Lminilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft

clean:
	rm -f $(NAME)
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all
