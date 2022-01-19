/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:59:49 by iugolin           #+#    #+#             */
/*   Updated: 2021/12/24 17:16:39 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *ap)
{
	ft_putchar_fd(va_arg(*ap, int), 1);
	return (1);
}

int	ft_print_str(va_list *ap)
{
	char	*str;
	int		i;

	str = va_arg(*ap, char *);
	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return (i);
}

int	ft_print_nbr(va_list *ap)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(va_arg(*ap, int));
	ft_putstr_fd(nb, 1);
	len = ft_strlen(nb);
	free(nb);
	return (len);
}

int	ft_print_unbr(va_list *ap)
{
	int				len;
	char			*nb;
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	nb = ft_uitoa_base(n, 10, 0);
	ft_putstr_fd(nb, 1);
	len = ft_strlen(nb);
	free(nb);
	return (len);
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
