/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:06:48 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/10 13:15:36 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_map_value(t_map *map)
{
	int	i;

	i = 0;
	if (map->line < 3)
		free_map("There are not enough lines.", map);
	while (map->map[map->line - 1][i])
	{
		if (map->map[map->line - 1][i] != '1')
			free_map("The map is not surrounded by walls.", map);
		i++;
	}
	if (map->player > 1)
		free_map("There are too many players.", map);
	if (map->player == 0)
		free_map("There is no player.", map);
	if (map->exit > 1)
		free_map("There are too many exits.", map);
	if (map->exit == 0)
		free_map("There is no exit.", map);
	if (map->collectible == 0)
		free_map("There is no collectible.", map);
}

void	fill_map_value(t_map *map, int i)
{
	while (map->map[map->line][i])
	{
		if ((map->line == 0 || i == 0 || i == map->line_size - 1) \
			&& map->map[map->line][i] != '1')
			free_map("The map is not surrounded by walls.", map);
		if (map->map[map->line][i] == 'P')
			map->player++;
		else if (map->map[map->line][i] == 'E')
			map->exit++;
		else if (map->map[map->line][i] == 'C')
			map->collectible++;
		else if (map->map[map->line][i] == 'R')
			map->enemy++;
		else if (map->map[map->line][i] == '0')
			map->empty_space++;
		else if (map->map[map->line][i] == '1')
			map->wall++;
		else if (map->map[map->line][i] != 0)
			free_map("Wrong character in the file.", map);
		i++;
	}
	map->collectible_at_start = map->collectible;
}

void	parsing(t_map *map)
{
	int	i;
	int	len;

	while (map->map[map->line] != 0)
	{
		i = 0;
		len = (int)ft_strlen(map->map[map->line]);
		if (len != map->line_size)
			free_map("The map isn't a rectangle.", map);
		fill_map_value(map, i);
		map->line++;
	}
	check_map_value(map);
	check_path(map);
}

void	check_file(char *file)
{
	char	*ext;
	size_t	len;

	ext = ft_strrchr(file, '.');
	if (ext == 0)
	{
		write(2, "Error\nWrong file name.", 23);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(ext);
	if (len < 4)
		len = 4;
	if (!ext || ft_strncmp(ext, ".ber", len) != 0)
	{
		write(2, "Error\nWrong file name.", 23);
		exit(EXIT_FAILURE);
	}
}

t_map	*create_map(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		free_map("Malloc error", map);
	check_file(file);
	initialize_map(file, map);
	parsing(map);
	return (map);
}
