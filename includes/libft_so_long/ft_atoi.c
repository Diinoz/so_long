/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:45:38 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/25 15:41:48 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		minus;
	long	res;
	long	temp;

	minus = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
		minus = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		temp = res;
		res = res * 10 + *str - 48;
		str++;
		if (res < temp && minus == 1)
			return (-1);
		if (res < temp && minus == 0)
			return (0);
	}
	return (res * minus);
}
