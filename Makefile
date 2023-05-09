NAME = so_long

SRC = main.c so_long_utils.c ft_check_game.c ft_make_map.c get_next_line.c ft_print_map.c ft_game.c ft_move_player.c ft_load_assets.c

SRCB = ./bonus/main_bonus.c ./bonus/so_long_utils_bonus.c ./bonus/ft_check_game_bonus.c ./bonus/ft_make_map_bonus.c\
			./bonus/get_next_line_bonus.c ./bonus/ft_print_map_bonus.c ./bonus/ft_game_bonus.c ./bonus/ft_move_player_bonus.c\
			./bonus/ft_load_assets_bonus.c

OBJS = ${SRC:.c=.o}

OBJSB = ${SRCB:.c=.o}

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

LIBFT.A = ./libft/libft.a

MLX = ./mlx

MLX.A = ./mlx/libmlx.a

RM = rm -rf

CC = gcc

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT.A} ${MLX.A}
		@${CC} ${CFLAGS} ${OBJS} ${LIBFT.A} ${MLX.A} -lz -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus: ${OBJSB} ${LIBFT.A} ${MLX.A}
		@${CC} ${CFLAGS} ${OBJSB} ${LIBFT.A} ${MLX.A} -lz -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}_bonus

${MLX.A}:
		@${MAKE} -C ${MLX}

${LIBFT.A}:
		@${MAKE} -C ${LIBFT}

clean:
		@${MAKE} -C ${LIBFT} fclean
		@${MAKE} -C ${MLX} clean
		@${RM} ${OBJS}
		@${RM} ${OBJSB}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
