/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:58:04 by nicordie          #+#    #+#             */
/*   Updated: 2024/02/15 11:58:07 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	**free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (map);
}

void	free_map(char *error, t_map *map)
{
	if (map->map != NULL)
		map->map = free_tab(map->map);
	if (map->path != NULL)
		map->path = free_tab(map->path);
	if (map->path_enemy != NULL)
		map->path_enemy = free_tab(map->path_enemy);
	if (map->path_exit != NULL)
		map->path_exit = free_tab(map->path_exit);
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
	if (data->enemy)
		mlx_destroy_image(data->mlx_ptr, data->enemy);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	data->map->map = free_tab(data->map->map);
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
	mlx_destroy_image(data->mlx_ptr, data->enemy);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->map->map = free_tab(data->map->map);
	free(data->map);
	exit(0);
}
