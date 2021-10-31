NAME =	so_long

INC =	include

SRCS =	srcs/main.c \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c \
	srcs/ft_putnbr.c \
	srcs/ft_split.c

MLX = mlx_linux

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

FLAGS_MLX=-L/usr/lib -lXext -lX11 -lm

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS) 
	-make -C mlx_linux
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux $(FLAGS_MLX) -Imlx_linux -o $(NAME) 

clean :
	$(RM) $(OBJS)

fclean : clean
	-make clean -C mlx_linux 
	$(RM) $(NAME)

re : fclean all
