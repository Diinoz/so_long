/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:04:16 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/09 11:57:16 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_line(char *next_line)
{
	int	i;

	i = 0;
	if (!next_line)
		return (0);
	while (next_line[i] && next_line[i] != '\n')
	{
		i++;
		if (next_line[i] == '\n')
			return (1);
	}
	return (0);
}

char	*new_next_line(char *next_line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (!next_line[i])
	{
		free(next_line);
		return (NULL);
	}
	if (next_line[i] == '\n')
		i++;
	new_line = ft_calloc((ft_strlen(next_line) - i + 1), sizeof(char));
	if (!new_line)
		return (ft_free(next_line, NULL));
	while (next_line[i])
		new_line[j++] = next_line[i++];
	free(next_line);
	return (new_line);
}

char	*line_read(char *next_line)
{
	char	*get_next_line;
	int		i;

	i = 0;
	if (!next_line[0])
		return (NULL);
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (next_line[i] == '\n')
		i++;
	get_next_line = malloc(sizeof(char) * (i + 1));
	if (!get_next_line)
		return (NULL);
	get_next_line[i] = 0;
	i--;
	while (i >= 0)
	{
		get_next_line[i] = next_line[i];
		i--;
	}
	return (get_next_line);
}

char	*ft_read(int fd, char *next_line)
{
	char	*buffer;
	ssize_t	nbytes;

	if (!next_line)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(next_line, NULL));
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
			return (ft_free(next_line, buffer));
		buffer[nbytes] = 0;
		next_line = ft_strjoin(next_line, buffer);
		if (!next_line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*get_next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (next_line == NULL)
		next_line = ft_calloc(1, sizeof(char));
	if (!next_line)
		return (NULL);
	if (check_line(next_line) == 0)
	{
		next_line = ft_read(fd, next_line);
		if (!next_line)
			return (NULL);
	}
	get_next_line = line_read(next_line);
	if (!get_next_line)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	next_line = new_next_line(next_line);
	return (get_next_line);
}
