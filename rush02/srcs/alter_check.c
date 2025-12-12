/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:58:33 by amerrouc          #+#    #+#             */
/*   Updated: 2018/08/19 20:30:47 by falupine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_line24(char *str, int col, int *auth)
{
	int		i;
	int		a;

	if ((str[0] == 'A') & (str[col] == 'A'))
		auth[2] = 1;
	if ((str[0] == 'A') & (str[col] == 'C'))
	{
		auth[3] = 1;
		auth[4] = 1;
	}
	i = 1;
	a = 1;
	while (i < col - 1)
	{
		if (str[i] != 'B')
			a = 0;
		i++;
	}
	i = 0;
	while (i < 5)
		auth[i++] *= a;
}

void	check_col24(char *str, int line, int *auth)
{
	int		i;
	int		j;
	int		a;

	if ((str[0] == 'A') & (str[2 * (line - 1)] == 'A'))
		auth[3] = 1;
	if ((str[0] == 'A') & (str[2 * (line - 1)] == 'C'))
	{
		auth[2] = 1;
		auth[4] = 1;
	}
	i = 0;
	j = 2;
	a = 1;
	while (j < (2 * (line - 1) - 1))
	{
		if (str[j] != 'B')
			a = 0;
		j += 2;
	}
	while (i < 5)
		auth[i++] *= a;
}

void	alt_check12(char *str, int incr, int len, int *auth)
{
	int		i;
	char	c;

	if ((str[0] == 'o') & (str[len - (incr - 1)] == 'o'))
		auth[0] = 1;
	if ((str[0] == '/') & (str[len - (incr - 1)] == '\\'))
		auth[1] = 1;
	i = incr;
	if (auth[0])
	{
		if (incr == 1)
			c = '-';
		else
			c = '|';
	}
	else
		c = '*';
	while (i < len - (incr - 1))
	{
		if (str[i] != c)
			auth[incr - 1] = 0;
		i += incr;
	}
}

void	check_1(char *str, int *auth)
{
	if (str[0] == 'o')
		auth[0] = 1;
	else if (str[0] == '/')
		auth[1] = 1;
	else if (str[0] == 'A')
	{
		auth[2] = 1;
		auth[3] = 1;
		auth[4] = 1;
	}
}

void	alter_check(char *str, int line, int col, int *auth)
{
	int		incr;
	int		len;

	if (col == 0)
	{
		len = 2 * line - 1;
		incr = 2;
	}
	else
	{
		len = col;
		incr = 1;
	}
	if (line == (col + 1))
		check_1(str, auth);
	else if ((str[0] == 'o') || (str[0] == '/'))
		alt_check12(str, incr, len, auth);
	else
	{
		if (line == 1)
			check_line24(str, col, auth);
		else
			check_col24(str, line, auth);
	}
}
