/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:19:23 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/15 15:01:48 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_start(unsigned int a, int j, int k)
{
	char				*str;
	unsigned int		i;

	i = 1;
	while (i * 10 <= a && i <= 100000000)
	{
		i = i * 10;
		k++;
	}
	str = malloc (sizeof(char) * (k + 1));
	if (!str)
		return (0);
	if (j == 1)
		str[0] = 45;
	while (i > 0)
	{
		str[j] = (a / i) + 48;
		a = a % i;
		j++;
		i = i / 10;
	}
	str[j] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	a;
	int				j;
	int				k;

	j = 0;
	k = 1;
	if (n < 0)
	{
		a = -n;
		j = 1;
		k++;
	}
	else
		a = n;
	str = ft_itoa_start(a, j, k);
	if (!str)
		return (0);
	return (str);
}
