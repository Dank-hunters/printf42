/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 08:41:39 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/15 16:33:13 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	def_size(t_size *size, t_struct *flag, t_here *here)
{
	int	i;

	if (size->dot == 0 && here->exdot && flag->i == 0)
		size->compt = 0;
	i = size->compt;
	if (size->dot > i)
		i = size->dot;
	if (flag->i < 0)
	{
		size->compt -= 1;
		if (size->dot > size->compt && size->num > size->dot)
			size->num -= 1;
		if (size->zero > size->dot && size->compt < size->dot)
			size->zero -= 1;
	}
	return (i);
}

void	new_deal_with_dot(t_struct *flag, t_here *here, t_size *size, int y)
{
	if (here->exzero)
		ft_isspacefori(flag, y);
	if (flag->i < 0)
		flag->ret += write(1, "-", 1);
	ft_iszerofori(flag, size->dot - size->compt);
}

void	ft_minusabsi(t_struct *flag, t_size *size, t_here *here)
{
	int	i;
	int	y;

	i = def_size(size, flag, here);
	y = size->zero - i;
	i = size->num - i;
	if (here->exnum)
		ft_isspacefori(flag, i);
	if (here->exnum && here->exist == 1 && flag->i < 0)
		flag->ret += write(1, "-", 1);
	if (!here->exdot && here->exzero)
	{
		if (flag->i < 0)
			flag->ret += write(1, "-", 1);
		ft_iszerofori(flag, y);
	}
	else if (here->exdot)
		new_deal_with_dot(flag, here, size, y);
	if (!(size->dot == 0 && here->exdot && flag->i == 0))
		ft_putnbr(flag->i, flag);
}

void	i_format(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	if (here->exist == 0)
	{
		if (flag->i < 0)
			flag->ret += write(1, "-", 1);
		ft_putnbr(flag->i, flag);
	}
	if (here->exmin == 1)
	{
		if (!here->exdot)
			nodoti(str, here, flag, size);
		else if (here->exdot)
			ft_pre_doti(flag, here, size);
	}
	else if (here->exmin == 0 && here->exist > 0)
		ft_minusabsi(flag, size, here);
}
