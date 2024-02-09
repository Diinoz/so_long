/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:12:24 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/26 15:38:01 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && len - i > 0)
	{
		j = 0;
		while (*(haystack + i + j) && len - i - j > 0
			&& (*(haystack + i + j) == *(needle + j)))
			j++;
		if (*(needle + j) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
