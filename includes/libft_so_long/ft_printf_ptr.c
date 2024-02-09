/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:43:16 by nicordie          #+#    #+#             */
/*   Updated: 2023/06/08 12:00:54 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr_hex(unsigned long long ptr, char *base, int len)
{
	if (ptr < 16)
	{
		if (write (1, &base[ptr], 1) == -1)
			return (-1);
		len++;
	}
	else
	{
		len = ft_print_ptr_hex(ptr / 16, base, len);
		if (len == -1)
			return (len);
		len = ft_print_ptr_hex(ptr % 16, base, len);
	}
	return (len);
}

int	ft_print_ptr(void *ptr, int len)
{
	char	*base;

	base = "0123456789abcdef";
	len = ft_print_str("0x", len);
	if (len == -1)
		return (len);
	if (ptr == 0)
	{
		len = ft_print_char('0', len);
		if (len == -1)
			return (len);
	}
	else
		len = ft_print_ptr_hex((unsigned long long) ptr, base, len);
	return (len);
}
