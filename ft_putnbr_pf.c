/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanuelrosarioalmonte <enmanuelrosario    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:29:22 by adiaz-be          #+#    #+#             */
/*   Updated: 2024/10/16 19:02:09 by enmanuelros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_putnbr_pf((num / 10), counter);
		ft_putchar_pf('8', counter);
	}
	else if (num < 0)
	{
		ft_putchar_pf('-', counter);
		ft_putnbr_pf(-num, counter);
	}
	else
	{
		if (num > 9)
			ft_putnbr_pf((num / 10), counter);
		ft_putchar_pf(('0' + num % 10), counter);
	}
}
