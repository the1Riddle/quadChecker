/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falupine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:36:06 by falupine          #+#    #+#             */
/*   Updated: 2018/08/19 21:55:48 by falupine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		*ft_check(char *str, int line, int col)
{
	int		*ans;
	int		i;
	t_fct	f[5];

	f[0] = &ft_check_rush00;
	f[1] = &ft_check_rush01;
	f[2] = &ft_check_rush02;
	f[3] = &ft_check_rush03;
	f[4] = &ft_check_rush04;
	ans = malloc(sizeof(int) * 5);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (i < 5)
		ans[i++] = 0;
	i = 0;
	if ((col > 1) & (line > 1))
	{
		while (i++ < 5)
			ans[i - 1] = f[i - 1](str, line, col);
	}
	else
		alter_check(str, line, col, ans);
	return (ans);
}

void	ft_display(int *ans, int line, int col)
{
	int	i;
	int	f;

	i = 0;
	f = 1;
	while (i < 5)
	{
		if (ans[i])
		{
			if (f == 0)
				ft_putstr(" || ");
			ft_putstr("[colle-0");
			ft_putnbr(i);
			ft_putstr("] ");
			ft_putchar('[');
			ft_putnbr(col);
			ft_putchar(']');
			ft_putstr(" [");
			ft_putnbr(line);
			ft_putchar(']');
			f = 0;
		}
		i++;
	}
	ft_putchar('\n');
}

int		ft_good(int *ans)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (ans[i])
			return (1);
		i++;
	}
	return (0);
}

void	rush02(char *str)
{
	int i;
	int v;
	int	*ans;

	i = 0;
	v = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			v++;
		i++;
	}
	i = ((i - 1) / v);
	ans = ft_check(str, v, i - 1);
	if (ans == NULL)
		ft_putstr("\n");
	if (ft_good(ans))
		ft_display(ans, i, v);
	else
		ft_putstr("aucune\n");
}
