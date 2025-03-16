# Variables
NAME = fractol
CC = cc
<<<<<<< HEAD
CFLAGS = -Wall -Wextra -Werror
MLX = ./minilibx-linux/libmlx.a -lX11 -lXext -lm
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
       mandelbrot.c \
       julia.c \
       minilibx-utils.c \
       color-utils.c \
       init_fractal.c \

=======
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MLX = /home/ruortiz-/42-projects/fract-ol/minilibx-linux/libmlx.a -lX11 -lXext -lm
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = main.c mandelbrot.c julia.c minilibx-utils.c \
	   color-utils.c color-transform.c color-schemes.c\
	   color-schemes2.c
>>>>>>> 2e72583 (optimizacion de archivos)
OBJS = $(SRCS:.c=.o)
HEADER = fractol.h

# Reglas
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
