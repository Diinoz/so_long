/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:44:31 by nicordie          #+#    #+#             */
/*   Updated: 2023/10/18 15:08:50 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s2)
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	while (s1[++i] != 0)
		string[i] = s1[i];
	while (s2[j] != 0)
		string[i++] = s2[j++];
	string[i] = 0;
	free(s1);
	return (string);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	while (*(s + i) != (char) c && *(s + i))
		i++;
	if (*(s + i) == (char) c)
		ptr = (char *)(s + i);
	else
		return (NULL);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*ptr;
	size_t	i;
	size_t	total_size;

	total_size = count * size;
	i = 0;
	p = malloc(total_size);
	if (!p)
		return (0);
	ptr = p;
	while (i < total_size)
	{
		*ptr = 0;
		i++;
		if (i < total_size)
			ptr++;
	}
	return (p);
}

char	*ft_free(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (NULL);
}
