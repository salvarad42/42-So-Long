NAME = so_long

SRCS = main.c ft_check_args.c ft_make_map.c ft_check_map.c ft_check_exit.c ft_check_width.C

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -stdlib=libstdc++

${NAME}: ${OBJS}
		@${MAKE} bonus -C ./Libft
		gcc ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

all: ${NAME}

clean:	@${MAKE} -C ./libft fclean
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

debug: CFLAGS += -g
debug: ${NAME}