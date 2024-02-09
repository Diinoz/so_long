/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:01:11 by nicordie          #+#    #+#             */
/*   Updated: 2023/06/08 11:59:42 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int nbr, char format, int len)
{
	char			*base;

	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 16)
	{
		if (write (1, &base[nbr], 1) == -1)
			return (-1);
		len++;
	}
	else
	{
		len = ft_print_hex(nbr / 16, format, len);
		if (len == -1)
			return (len);
		len = ft_print_hex(nbr % 16, format, len);
	}
	return (len);
}
