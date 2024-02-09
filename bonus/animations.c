/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:34:03 by nicordie          #+#    #+#             */
/*   Updated: 2024/02/09 16:34:06 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	replace_player(t_data *data)
{
	int	width;
	int	height;

	width = WIDTH;
	height = HEIGHT;
	data->player.player = mlx_xpm_file_to_image(data->mlx_ptr, \
								"sprites/player2.xpm", &width, &height);
	if (!data->player.player)
		destroy_window_error("Sprite not found.", data);
}

void	open_exit(t_data *data)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = WIDTH;
	height = HEIGHT;
	i = 0;
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, \
								"sprites/exit-open.xpm", &width, &height);
	if (!data->exit)
		destroy_window_error("Sprite not found.", data);
	while (i < data->map->line)
	{
		j = 0;
		while (data->map->map[i][j] != 0)
		{
			if (data->map->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->exit, j * HEIGHT, i * WIDTH);
			j++;
		}
		i++;
	}
}
