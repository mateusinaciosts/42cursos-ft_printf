/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:01:01 by matsanto          #+#    #+#             */
/*   Updated: 2023/06/30 15:27:21 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_lower(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 15)
		len = len + ft_put_hex_lower(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], sizeof(char));
	len++;
	return (len);
}

int	ft_put_hex_upper(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 15)
		len = len + ft_put_hex_upper(nbr / 16);
	write(1, &"0123456789ABCDEF"[nbr % 16], sizeof(char));
	len++;
	return (len);
}
