/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_for_flag_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:36:02 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/15 17:07:37 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	forzero(const char *str, t_size *size, t_here *here)
{
	size->i++;
	while (str[size->i] >= '0' && str[size->i] <= '9')
	{
		size->zero = size->zero * 10 + str[size->i] - 48;
		size->i++;
	}
	here->exzero = 1;
}

void	fornum(const char *str, t_size *size, t_here *here)
{
	while (str[size->i] >= '0' && str[size->i] <= '9')
	{
		size->num = size->num * 10 + str[size->i] - 48;
		size->i++;
	}
	here->exnum = 1;
}

void	fordot(const char *str, t_size *size, t_here *here)
{
	size->i++;
	while (str[size->i] >= '0' && str[size->i] <= '9')
	{
		size->dot = size->dot * 10 + str[size->i] - 48;
		size->i++;
	}
	here->exdot = 1;
}

void	forminus(const char *str, t_size *size, t_here *here)
{
	size->i++;
	while (str[size->i] == '0')
		size->i++;
	while (str[size->i] >= '0' && str[size->i] <= '9')
	{
		size->minus = size->minus * 10 + str[size->i] - 48;
		size->i++;
	}
	here->exmin = 1;
}
