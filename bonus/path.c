/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:58:34 by nicordie          #+#    #+#             */
/*   Updated: 2024/02/15 11:58:35 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (map->path_exit[i][j] != 0 && map->path_exit[i][j] != '\n' \
				&& map->path_exit[i][j] != 'E')
			j++;
		if (map->path_exit[i][j] == 'E')
			free_map("Impossible to reach the exit.", map);
		else
			i++;
	}
}

void	check_enemies(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (map->path_enemy[i][j] != 0 && map->path_enemy[i][j] != 'R')
			j++;
		if (map->path_enemy[i][j] == 'R')
			free_map("Impossible to get all the enemies.", map);
		else
			i++;
	}
}

void	check_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (map->path[i][j] != 0 && map->path[i][j] != 'C')
			j++;
		if (map->path[i][j] == 'C')
			free_map("Impossible to get all the collectibles.", map);
		else
			i++;
	}
}

static int	travel_map(int i, int j, char **path, char c)
{
	char	exit;

	if (c == 'R' || c == 'E')
		exit = 'E';
	else 
		exit = c;
	if (path[i][j] != '1' && path[i][j] != exit && path[i][j] != c)
	{
		path[i][j] = '1';
		if (travel_map(i, j - 1, path, c))
			return (1);
		else if (travel_map(i + 1, j, path, c))
			return (1);
		else if (travel_map(i - 1, j, path, c))
			return (1);
		else if (travel_map(i, j + 1, path, c))
			return (1);
	}
	return (0);
}

void	check_path(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->path[i][j] != 'P')
	{
		j = 0;
		while (map->path[i][j] != 0 && map->path[i][j] != 'P')
			j++;
		if (map->path[i][j] != 'P')
			i++;
	}
	travel_map(i, j, map->path, 'R');
	check_collectibles(map);
	travel_map(i, j, map->path_enemy, 'E');
	check_enemies(map);
	travel_map(i, j, map->path_exit, 'x');
	check_exit(map);
	map->path = free_tab(map->path);
	map->path_enemy = free_tab(map->path_enemy);
	map->path_exit = free_tab(map->path_exit);
}
