/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:07 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/12 12:30:09 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void replace_player(t_data *data)
{
    int width;
    int height;

    width = WIDTH;
    height = HEIGHT;
    data->player.player = mlx_xpm_file_to_image(data->mlx_ptr, 
                                    "sprites/player2.xpm", &width, &height);
    if (!data->player.player)
        destroy_window_error("Sprite not found.", data);
}

void replace_exit(t_data *data)
{
    int width;
    int height;
    int i;
    int j;

    width = WIDTH;
    height = HEIGHT;
    i = 0;
    data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/exit-open.xpm", 
                                        &width, &height);
    if (!data->exit)
        destroy_window_error("Sprite not found.", data);
    while (i <data->map->line)
    {
        j = 0;
        while (data->map->map[i][j] != 0)
        {
            if (data->map->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
                                data->exit, j * HEIGHT, i * WIDTH);
            j++;
        }
        i++;
    }
}

void fill_first_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->map->line)
    {
        j = 0;
        while (data->map->map[i][j] != 0)
        {    
            if (data->map->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
                                data->wall, j * HEIGHT, i * WIDTH);
            if (data->map->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
                                data->collectible, j * HEIGHT, i * WIDTH);
            if (data->map->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
                                data->exit, j * HEIGHT, i * WIDTH);
            if (data->map->map[i][j] == 'P')
            {
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
                                data->player.player, j * HEIGHT, i * WIDTH);
                data->player.i = i;
                data->player.j = j;
            }
            j++;
        }
        i++;
    }
}

void fill_background(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->map->line)
    {
        j = 0;
        while (data->map->map[i][j] != 0)
        {
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
                                    data->empty_space, j * HEIGHT, i * WIDTH);
            j++;
        }
        i++;
    }
    fill_first_map(data);
}

void create_sprites(t_data *data)
{
    int width;
    int height;

    width = WIDTH;
    height = HEIGHT;

    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/wall.xpm", 
                                &width, &height);
    data->empty_space = mlx_xpm_file_to_image(data->mlx_ptr, 
                                "sprites/empty_space.xpm", &width, &height);
    data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, 
                                "sprites/collectible.xpm", &width, &height);  
    data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/exit.xpm", 
                                &width, &height);
    data->player.player = mlx_xpm_file_to_image(data->mlx_ptr, 
                                "sprites/player.xpm", &width, &height);
    if (!data->wall || !data->empty_space || !data->collectible 
        || !data->exit || !data->player.player)
        destroy_window_error("Sprite not found", data);
    fill_background(data);
}