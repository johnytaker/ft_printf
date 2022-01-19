/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:12:22 by iugolin           #+#    #+#             */
/*   Updated: 2021/12/24 17:12:44 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digit_couner(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned long n, int base, int uppercase)
{
	char	*base_arr;
	char	*rtn;
	int		len;

	len = digit_couner(n, base);
	rtn = (char *)malloc(sizeof(char) * len + 1);
	if (!rtn)
		return (NULL);
	*(rtn + len) = '\0';
	if (n == 0)
		rtn[0] = '0';
	if (uppercase)
		base_arr = "0123456789ABCDEF";
	else
		base_arr = "0123456789abcdef";
	while (n)
	{
		*(rtn + (--len)) = base_arr[n % base];
		n /= base;
	}
	return (rtn);
}
