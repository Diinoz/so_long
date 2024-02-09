/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:03:38 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/05 12:44:21 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while ((*ptr1 || *ptr2) && n > 0 && (*ptr1 == *ptr2))
	{
		ptr1++;
		ptr2++;
		n--;
	}
	if (n)
		return (*ptr1 - *ptr2);
	return (0);
}
