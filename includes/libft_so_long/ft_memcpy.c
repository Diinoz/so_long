/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:24:01 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/19 16:09:05 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	const char		*ptr2;

	ptr = dst;
	ptr2 = src;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		*ptr = *ptr2;
		ptr++;
		ptr2++;
		n--;
	}
	return (dst);
}
