/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:36:02 by nicordie          #+#    #+#             */
/*   Updated: 2023/04/26 14:32:24 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*ptr1 == *ptr2)
		{
			ptr1++;
			ptr2++;
			n--;
		}
		else
			return (*ptr1 - *ptr2);
	}
	return (0);
}
