/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falupine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:21:48 by falupine          #+#    #+#             */
/*   Updated: 2018/08/16 10:56:40 by falupine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putnbr(int nb)
{
	unsigned int res;

	res = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		res = -nb;
	}
	if (res <= 9)
	{
		ft_putchar(res + 48);
	}
	if (res >= 10)
	{
		ft_putnbr(res / 10);
		ft_putnbr(res % 10);
	}
}
