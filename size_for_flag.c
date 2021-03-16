/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_for_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:36:36 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:13:21 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	forwith2(const char *str, int i, t_size *size, t_here *here)
{
	if (size->with >= 0 && str[i] == '.')
	{
		size->dot = size->with;
		here->exdot = 1;
	}
	else if (str[i] == '-')
	{
		size->minus = size->with;
		here->exmin = 1;
	}
	else if (str[i] == '%' && str[i + 1] == '0')
	{
		size->zero = size->with;
		here->exzero = 1;
	}
	else if (str[i] == '%')
	{
		size->num = size->with;
		here->exnum = 1;
	}
}

void	forwith(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	int	i;

	i = size->i - 1;
	size->with = va_arg(flag->vargs, int);
	here->exwith = 1;
	while (str[i] == '0')
		i--;
	if (str[i] == '.' && size->with < 0)
		here->exdot = 0;
	if (size->with < 0 && str[i] != '.')
	{
		here->exmin = 1;
		size->minus = size->with * -1;
	}
	else
		forwith2(str, i, size, here);
	size->i++;
}
