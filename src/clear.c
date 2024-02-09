/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:15:03 by nicordie          #+#    #+#             */
/*   Updated: 2024/02/01 14:15:07 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(char *error, t_map *map)
{
	if (map->map != 0)
		free_tab(map->map);
	if (map->path != 0)
		free_tab(map->path);
	if (map->path_exit != 0)
		free_tab(map->path_exit);
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	free(map);
	exit(EXIT_FAILURE);
}

void	destroy_window_error(char *error, t_data *data)
{
	if (data->collectible)
		mlx_destroy_image(data->mlx_ptr, data->collectible);
	if (data->empty_space)
		mlx_destroy_image(data->mlx_ptr, data->empty_space);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->player.player)
		mlx_destroy_image(data->mlx_ptr, data->player.player);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	free(data->mlx_ptr);
	free_tab(data->map->map);
	free(data->map);
	exit(EXIT_FAILURE);
}

int	destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->collectible);
	mlx_destroy_image(data->mlx_ptr, data->empty_space);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->player.player);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free_tab(data->map->map);
	free(data->map);
	exit(0);
}
