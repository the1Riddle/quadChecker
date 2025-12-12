/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falupine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:38:21 by falupine          #+#    #+#             */
/*   Updated: 2018/08/19 21:59:38 by falupine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		main(int argc, char **argv)
{
	char	*buf;
	int		offset;
	char	*tmp;

	tmp = argv[0];
	offset = 0;
	if ((argc - 1) > 0)
	{
		ft_putchar('\n');
		return (0);
	}
	buf = reader();
	if (buf == NULL)
		return (0);
	rush02(buf);
	return (0);
}
