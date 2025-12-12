/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falupine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:38:55 by falupine          #+#    #+#             */
/*   Updated: 2018/08/19 22:00:02 by falupine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE (4096)

void	rush02(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_check_rush00(char *str, int col, int line);
int		ft_check_rush01(char *str, int col, int line);
int		ft_check_rush02(char *str, int col, int line);
int		ft_check_rush03(char *str, int col, int line);
int		ft_check_rush04(char *str, int col, int line);
int		*ft_check(char *str, int line, int col);
int		ft_strlen(char *str);
void	alter_check(char *str, int line, int col, int *auth);
char	*reader(void);
typedef	int	(*t_fct)(char*, int, int);

#endif
