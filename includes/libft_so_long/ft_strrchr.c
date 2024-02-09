/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:02:20 by nicordie          #+#    #+#             */
/*   Updated: 2023/04/28 13:53:09 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char) c)
			j = i;
		i++;
	}
	if ((char) c == 0)
		return ((char *)(s + i));
	if (*(s + j) == (char) c)
		return ((char *)(s + j));
	return (0);
}
