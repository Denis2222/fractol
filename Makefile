.PHONY: libft

SRCS = display.c \
	   draw.c \
	   setup.c \
	   key.c \
	   color.c \
	   t_cam.c \
	   t_dot.c \
	   t_double2.c \
	   print.c \
	   main.c

NAME = fractol
GCC_FLAG = -Wall -Werror -Wextra
CC = gcc -std=c89 #$(GCC_FLAG)

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
	$(CC) -o $@ $^ -Lminilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft -O3

clean:
	rm -f $(NAME)
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all
