/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:39:16 by nicordie          #+#    #+#             */
/*   Updated: 2024/01/10 12:48:50 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list ap, char format, int len)
{
	if (format == 'c')
		len = ft_print_char(va_arg(ap, int), len);
	else if (format == 's')
		len = ft_print_str(va_arg(ap, char *), len);
	else if (format == 'p')
		len = ft_print_ptr(va_arg(ap, void *), len);
	else if (format == 'd')
		len = ft_print_nbr(va_arg(ap, int), len);
	else if (format == 'i')
		len = ft_print_nbr(va_arg(ap, int), len);
	else if (format == 'u')
		len = ft_print_unsigned(va_arg(ap, unsigned int), len);
	else if (format == 'x')
		len = ft_print_hex(va_arg(ap, int), format, len);
	else if (format == 'X')
		len = ft_print_hex(va_arg(ap, int), format, len);
	else if (format == '%')
		len = ft_print_char('%', len);
	else
		len = -1;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		len;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '%')
		{
			len = ft_format(ap, str[i + 1], len);
			i++;
		}
		else
			len = ft_print_char(str[i], len);
		if (len == -1)
			return (len);
		i++;
	}
	va_end(ap);
	return (len);
}
