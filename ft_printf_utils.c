/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:01:04 by matsanto          #+#    #+#             */
/*   Updated: 2023/06/30 15:17:10 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len])
		{
			write(1, &str[len], 1);
			len++;
		}
	}
	else
		len = len + ft_putstr("(null)");
	return (len);
}

int	ft_putptr(unsigned long nbr, int flag)
{
	int	len;

	len = 0;
	if (nbr == 0)
	{
		len = ft_putstr("(nil)");
		return (len);
	}
	if (flag == 0)
		len = len + ft_putstr("0x");
	if (nbr > 15)
		len = len + ft_putptr(nbr / 16, 1);
	write(1, &"0123456789abcdef"[nbr % 16], sizeof(char));
	len++;
	return (len);
}

int	ft_putnbr(int nb)
{
	unsigned int	number;
	int				len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
		number = nb * -1;
	}
	else
		number = nb;
	if (number >= 10)
	{
		len = len + ft_putnbr(number / 10);
	}
	ft_putchar(number % 10 + '0');
	len++;
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len = len + ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	len++;
	return (len);
}
