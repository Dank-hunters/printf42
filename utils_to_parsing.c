/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:10:54 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:02:16 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_here(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] != '%')
		return (0);
	i++;
	while (str[i])
	{
		if (ft_ischar(str[i], "cspdiuxX%") == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_ischar(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_dontprint(const char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1 && str[0] == '%')
		return (1);
	i++;
	while (str[i] && ft_ischar(str[i], "lh$# .+-*0123456789") == 1)
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

void	ft_percent(t_struct *flag, t_here *here, t_size *size)
{
	if (here->exnum && here->exmin != 1)
		ft_isspacefori(flag, size->num - 1);
	if (here->exzero && here->exmin != 1)
		ft_iszerofori(flag, size->zero - 1);
	ft_putchar(flag->percent, flag);
	if (here->exmin)
		ft_isspacefori(flag, size->minus - 1);
}
