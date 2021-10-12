NAME = so_long

INC =	include

SRCS =	srcs/main.c \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c \
	srcs/ft_putnbr.c \
	srcs/ft_split.c

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLX = minilibx_opengl_20191021
else
	MLX = minilibx-linux
endif

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) -I$(INC) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(MLX)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(MLX)/libmlx.a -lm -o $(NAME)

$(MLX)/libmlx.a:
	cd $(MLX) && make

clean :
	$(RM) $(OBJS)
	cd $(MLX) && make clean

fclean : clean
	$(RM) $(NAME)
	cd $(MLX) && make clean

re : fclean all
