/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:28:52 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/10 12:38:51 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_new_pos(t_data *data, int i, int j)
{
	i += data->player.i;
	j += data->player.j;
	if ((data->map->map[i][j] == 'E' && data->map->collectible != 0) \
			|| data->map->map[i][j] == '1')
		return (0);
	data->map->map[data->player.i][data->player.j] = '0';
	if (data->map->map[i][j] == 'C')
		data->map->collectible--;
	if (data->map->map[i][j] == 'E' && data->map->collectible == 0)
	{
		data->map->map[i][j] = 'P';
		return (2);
	}
	data->map->map[i][j] = 'P';
	return (1);
}

void	move_player(t_data *data, int i, int j)
{
	int	result;

	result = check_new_pos(data, i, j);
	if (result == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->empty_space, data->player.j * HEIGHT, data->player.i * WIDTH);
		data->player.i += i;
		data->player.j += j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->empty_space, data->player.j * HEIGHT, data->player.i * WIDTH);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->player.player, data->player.j * HEIGHT, \
							data->player.i * WIDTH);
		data->step++;
		ft_printf("Steps : %d\n", data->step);
	}
	if (result == 2)
		destroy_window(data);
	if (result == 0)
		ft_printf("You cannot move this way.\n");
}

int	key_pressed(int key, t_data *data)
{
	if (key == 0)
		move_player(data, 0, -1);
	if (key == 1)
		move_player(data, 1, 0);
	if (key == 2)
		move_player(data, 0, 1);
	if (key == 13)
		move_player(data, -1, 0);
	if (key == 53)
		destroy_window(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	data;

	if (argc != 2)
		return (0);
	map = create_map(argv[1]);
	data.map = map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map->line_size * WIDTH, \
									data.map->line * HEIGHT, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 0);
	data.step = 0;
	create_sprites(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, destroy_window, &data);
	mlx_loop(data.mlx_ptr);
}
