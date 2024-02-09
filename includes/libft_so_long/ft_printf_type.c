/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:07:46 by nicordie          #+#    #+#             */
/*   Updated: 2023/06/08 11:59:06 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c, int len)
{
	unsigned char	character;

	character = (unsigned char) c;
	if (write (1, &character, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_print_str(char *str, int len)
{
	if (str == 0)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (len + 6);
	}
	else
	{
		if (write (1, str, ft_strlen2(str)) == -1)
			return (-1);
		return (len + ft_strlen2(str));
	}
}

int	ft_print_nbr(int n, int len)
{
	unsigned int	a;

	if (n < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		a = -n;
		len++;
	}
	else
		a = n;
	if (a < 10)
	{
		len = ft_print_char(a + 48, len);
		if (len == -1)
			return (len);
	}
	if (a > 9)
	{
		len = ft_print_nbr(a / 10, len);
		if (len == -1)
			return (len);
		len = ft_print_nbr(a % 10, len);
	}
	return (len);
}

int	ft_print_unsigned(unsigned int a, int len)
{
	if (a < 10)
	{
		len = ft_print_char(a + 48, len);
		if (len == -1)
			return (len);
	}
	if (a > 9)
	{
		len = ft_print_unsigned(a / 10, len);
		if (len == -1)
			return (-1);
		len = ft_print_unsigned(a % 10, len);
	}
	return (len);
}
