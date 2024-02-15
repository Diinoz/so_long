/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:22:55 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/10 13:01:30 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "libft_so_long/libft.h"
# define WIDTH 64
# define HEIGHT 64
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_map
{
	int		player;
	int		exit;
	int		collectible;
	int		wall;
	int		empty_space;
	int		line;
	int		line_size;
	char	**map;
	char	**path;
	char	**path_exit;
}			t_map;

typedef struct s_player
{
	int		i;
	int		j;
	void	*player;
}			t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*wall;
	void		*empty_space;
	void		*collectible;
	int			step;
	void		*exit;
	t_player	player;
	t_map		*map;
}				t_data;

t_map	*create_map(char *file);
void	check_map_value(t_map *map);
void	fill_map_value(t_map *map, int i);
void	parsing(t_map *map);
void	check_file(char *file);
void	check_exit(t_map *map);
void	check_collectibles(t_map *map);
void	check_path(t_map *map);
void	initialize_map(char *file, t_map *map);
void	create_sprites(t_data *data);
int		destroy_window(t_data *data);
void	destroy_window_error(char *error, t_data *data);
void	free_map(char *error, t_map *map);
char	**free_tab(char **map);
void	create_player(t_data *data);

#endif