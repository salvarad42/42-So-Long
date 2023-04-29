NAME = so_long

SRC = main.c ft_check_args.c ft_make_map.c ft_check_map.c ft_check_exit.c ft_check_width.c\
		get_next_line.c ft_print_map.c ft_game.c ft_move_player.c

OBJS = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -stdlib=libstdc++

LIBFT = ./libft

LIBFT.A = ./libft/libft.a

RM = rm -rf

CC = gcc

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT.A}
		@${CC} ${CFLAGS} ${OBJS} ${LIBFT.A} -o ${NAME}

${LIBFT.A}:
		@${MAKE} -C ${LIBFT}

clean:
		@${MAKE} -C ${LIBFT} fclean
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

debug: CFLAGS += -g
debug: ${NAME}