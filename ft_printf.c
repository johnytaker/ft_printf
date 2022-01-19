/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2021/12/24 14:49:19 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list *ap, char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(ap);
	else if (format == 's')
		print_length += ft_print_str(ap);
	else if (format == 'p')
		print_length += ft_print_ptr(ap);
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(ap);
	else if (format == 'u')
		print_length += ft_print_unbr(ap);
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(ap, format);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		print_length;

	print_length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			print_length += ft_formats(&ap, *(str++ + 1));
		else
			print_length += write(1, str, 1);
		if (*str)
			str++;
	}
	va_end(ap);
	return (print_length);
}
