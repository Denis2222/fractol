.PHONY: libft minilibx

SRCS = draw.c \
	   setup.c \
	   hook.c \
	   key.c \
	   color.c \
	   print.c \
	   t_cam.c \
	   t_dot.c \
	   t_complex.c \
	   t_pentagon.c \
	   fractal_mandelbrot.c \
	   fractal_julia.c \
	   fractal_pentagon.c \
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
	$(CC) -o $@ -c $^ -O3

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Lminilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft -O3

clean:
	rm -f $(NAME)
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all
