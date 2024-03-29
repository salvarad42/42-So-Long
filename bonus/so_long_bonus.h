/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:43:20 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/08 20:31:37 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

# define BUFFER_SIZE 42
# define SIZE_H 50
# define SIZE_W 50
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_SCAPE 53
# define FONT_WIDTH 10
# define FONT_HEIGHT 20
# define PLAYER_ANIMATION 2000

typedef enum s_player_sprite
{
	left_alive,
	left_jump,
	left_dead,
	left_exit,
	right_alive,
	right_jump,
	right_dead,
	right_exit
}	t_player_sprite;

typedef struct s_dfs
{
	int	**visited;
	int	exit;
	int	collectible;
}	t_dfs;

typedef struct s_size
{
	int	height;
	int	width;
}	t_size;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	t_size	*size;
	void	*img;
}	t_img;

typedef struct s_assets
{
	t_img	*floor;
	t_img	*wall;
	t_img	**player;
	t_img	*collectible;
	t_img	*enemy;
	t_img	**exit;
}	t_assets;

typedef struct s_player
{
	int				movements;
	t_player_sprite	sprite;
	t_pos			*pos;
	int				frames;
}	t_player;

typedef struct s_components
{
	int			collectible;
	t_player	*player;
	t_pos		*exit;
}	t_components;

typedef struct s_map
{
	char			**map;
	t_size			*size;
	t_components	*components;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	t_assets	*assets;
	void		*mlx;
	void		*mlx_win;
}	t_game;

t_map		*ft_make_map(char **argv);
void		ft_make_position(t_pos **pos, int x, int y);
void		ft_get_components(t_map *map);
void		ft_dfs_exit(int row, int col, t_map *map, t_dfs *dfs_args);
void		ft_check_walls(t_map *map);
int			ft_check_components(t_map *map, t_components *components);
void		ft_check_map(t_map *map);
void		ft_check_exit(t_map *map);
void		ft_check_width(char *str, int size);
char		*get_next_line(int fd);
void		ft_print_map(t_game *game);
void		ft_game(t_map *map);
void		ft_move_player(int key, t_game *game);
t_assets	*ft_load_assets(void *mlx);
void		ft_print_assets(t_game *game, t_pos pos);
void		ft_end_game(t_game *game);
int			ft_close_game(t_game *game);
int			ft_create_rgb(int t, int r, int g, int b);
void		ft_print_player(t_game *game, t_pos pos, t_player_sprite sprite);

#endif
