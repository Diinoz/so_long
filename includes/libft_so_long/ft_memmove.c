/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:43:30 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/19 15:18:30 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (!dst && !src)
		return (0);
	ptr = (unsigned char *) dst;
	ptr2 = (unsigned char *) src;
	i = 0;
	if (ptr > ptr2)
	{
		while (len-- > 0)
			ptr[len] = ptr2[len];
	}
	else
	{
		while (i < len)
		{
			ptr[i] = ptr2[i];
			i++;
		}
	}
	return (dst);
}
