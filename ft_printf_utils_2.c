/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:59:49 by iugolin           #+#    #+#             */
/*   Updated: 2021/12/24 17:16:51 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list *ap)
{
	int			len;
	char		*nb;
	uintptr_t	n;

	n = va_arg(*ap, unsigned long);
	ft_putstr_fd("0x", 1);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	nb = ft_uitoa_base(n, 16, 0);
	ft_putstr_fd(nb, 1);
	len = ft_strlen(nb) + 2;
	free(nb);
	return (len);
}

int	ft_print_hex(va_list *ap, const char format)
{
	int				len;
	char			*nb;
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	if (format == 'X')
		nb = ft_uitoa_base(n, 16, 1);
	else
		nb = ft_uitoa_base(n, 16, 0);
	ft_putstr_fd(nb, 1);
	len = ft_strlen(nb);
	free(nb);
	return (len);
}
