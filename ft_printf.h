/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:04:57 by iugolin           #+#    #+#             */
/*   Updated: 2021/12/24 14:44:59 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa_base(unsigned long n, int base, int uppercase);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *str, ...);
int		ft_print_char(va_list *ap);
int		ft_print_str(va_list *ap);
int		ft_print_nbr(va_list *ap);
int		ft_print_unbr(va_list *ap);
int		ft_print_percent(void);
int		ft_print_ptr(va_list *ap);
int		ft_print_hex(va_list *ap, char format);

#endif
