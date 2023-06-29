/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:01:01 by matsanto          #+#    #+#             */
/*   Updated: 2023/06/29 15:30:49 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex_lower(unsigned int nbr)
{
	if (nbr > 15)
		ft_put_hex_lower(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], sizeof(char));
	add_one_more(1);
}

void	ft_put_hex_upper(unsigned int nbr)
{
	if (nbr > 15)
		ft_put_hex_upper(nbr / 16);
	write(1, &"0123456789ABCDEF"[nbr % 16], sizeof(char));
	add_one_more(1);
}
