/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:02:37 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/11 12:02:39 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void check_exit(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->line)
    {
        j = 0;
        while (map->path[i][j] != 0 && map->path[i][j] != '\n' && map->path[i][j] != 'E')
            j++;
        if (map->path[i][j] == 'E')
            free_map("Impossible to reach the exit.", map);
        else
            i++;
    }
}

void check_collectibles(t_map *map)
{
    int i;
    int j;

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
    check_exit(map);
}

static int travel_map(int i, int j, char **path)
{
    if (path[i][j] != '1')
    {
        path[i][j] = '1';
        if (travel_map(i, j - 1, path))
            return (1);
        else if (travel_map(i + 1, j, path))
            return (1);
        else if (travel_map(i - 1, j, path))
            return (1);
        else if (travel_map(i, j + 1, path))
            return (1);
    }
    return (0);
}

void check_path(t_map *map)
{
    int i;
    int j;

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
    travel_map(i, j, map->path);
    check_collectibles(map);
    free_tab(map->path);
}