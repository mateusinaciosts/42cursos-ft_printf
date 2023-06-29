/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:01:08 by matsanto          #+#    #+#             */
/*   Updated: 2023/06/29 15:36:26 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_flag(char flag, va_list arg)
{
    if (flag == 'c')
        return (ft_putchar(va_arg(arg, int)));
    if (flag == 's')
        return (ft_putstr(va_arg(arg, char *)));
    if (flag == 'p')
        return (ft_putptr(va_arg(arg, unsigned long), 0));
    if (flag == 'd' || flag == 'i')
        return (ft_putnbr(va_arg(arg, int)));
    if (flag == 'u')
        return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
    if (flag == 'x')
        return (ft_put_hex_lower(va_arg(arg, unsigned int)));
    if (flag == 'X')
        return (ft_put_hex_upper(va_arg(arg, unsigned int)));
    if (flag == '%')
        return (ft_putchar('%'));
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	arg;

	if (!str)
		return (-1);
	len = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len = len + check_flag(*str, arg);
		}
		else
		{
			ft_putchar(*str);
			len++;
		}
		str++;
	}
	va_end(arg);
	return (len);
}
