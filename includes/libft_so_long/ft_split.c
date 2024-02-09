/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:01:06 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/25 11:59:02 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**size_of_strs(char const *s, char c)
{
	int		i;
	int		count;
	char	**strs;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		if (i != 0)
			count++;
		while (s[i] == c && s[i])
			i++;
	}
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (0);
	return (strs);
}

static char	*ft_another_strdup(char const *s, int i, int j)
{
	char	*split;

	split = malloc((j + 1) * sizeof(char));
	if (!split)
		return (0);
	split[j] = 0;
	while (j > 0)
	{
		split[j - 1] = s[i + j - 1];
		j--;
	}
	return (split);
}

static char	**ft_free2(char **split, int count)
{
	while (count >= 0)
	{
		free(split[count]);
		count--;
	}
	free(split);
	return (0);
}

static char	**ft_fill_split(char const *s, char c, char **split, int i)
{
	int	j;
	int	count;

	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		split[count] = ft_another_strdup(s, i, j);
		if (!split[count])
		{
			ft_free2(split, count);
			return (0);
		}
		count++;
		while (s[i + j] == c && s[i + j])
			j++;
		i += j;
	}
	split[count] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (0);
	i = 0;
	split = 0;
	split = size_of_strs(s, c);
	if (!split)
		return (0);
	split = ft_fill_split(s, c, split, i);
	if (!split)
		return (0);
	return (split);
}
