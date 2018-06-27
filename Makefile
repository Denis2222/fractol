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
GCC_FLAG = -Wall -Werror -Wextra -Lminilibx/ -lX11 -lXext -lmlx -lGLU -lGL -Llibft -lft -lm -lXxf86vm -lX11 -lXrandr -lXi
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

libft:
	make -C ./libft/

minilibx:
	make -C ./minilibx/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(GCC_FLAG)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all
