NAME = so_long

INC =	include

SRCS =	srcs/main.c \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c \
	srcs/ft_putnbr.c \
	srcs/ft_split.c \

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) -I$(INC) -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -Lminilibx-linux -lmlx -Iminilibx_linux -lXext -lX11 -lm -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
