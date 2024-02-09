/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:15:52 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/10 13:15:55 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char **get_map(int fd, t_map *mapper)
{
	char	*map_line;
	char	*line;
	char	**map;

	map_line = 0;
    mapper = 0;
	line = get_next_line(fd);
    if (!line)
        free_map("This file doesn't exist or is empty.", mapper);
	while (line)
	{
		map_line = ft_strjoin(map_line, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(map_line, '\n');
	free(map_line);
	if (!map)
		free_map("Cannot get the map.", mapper);
	return (map);
}

void initialize_map(char *file, t_map *map)
{
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->wall = 0;
	map->empty_space = 0;
	map->line = 0;
	map->map = get_map(open(file, O_RDONLY), map);
    map->path = get_map(open(file, O_RDONLY), map);
    map->path_exit = get_map(open(file, O_RDONLY), map);
	map->line_size = (int)ft_strlen(map->map[0]);
}