/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:41:28 by amerrouc          #+#    #+#             */
/*   Updated: 2018/08/19 21:58:26 by falupine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*add(char **str)
{
	char	*add;
	int		i;
	int		len;

	len = 0;
	while ((*str)[len])
		len++;
	add = malloc(sizeof(char) * (len + 2));
	if (add == NULL)
		return (NULL);
	add[len + 1] = '\0';
	i = 0;
	while (i < len)
	{
		add[i] = (*str)[i];
		i++;
	}
	free(*str);
	return (add);
}

char	*reader(void)
{
	char	*str;
	int		i;
	int		r;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[2] = '\0';
	i = 0;
	while ((r = read(0, str + i, 1)) != 0)
	{
		str = add(&str);
		i++;
	}
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	return (str);
}
