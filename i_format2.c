/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_format2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:01:22 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/15 17:17:46 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nodoti(const char *str, t_here *here, t_struct *flag, t_size *size)
{
	int	i;

	if (here->exist == 2 && here->exnum && here->exmin)
		size->num = size->minus;
	i = size->num - size->compt;
	if (flag->i < 0)
		flag->ret += write(1, "-", 1);
	if (!(size->minus > size->num))
		ft_isspace(str, flag, size, i);
	ft_putnbr(flag->i, flag);
	ft_isspace(str, flag, size, size->minus);
}

void	deal_with_dot(t_size *size, t_struct *flag, int i, int y)
{
	if (size->zero > size->dot)
		ft_iszerofori(flag, y);
	if (size->dot == 0 && flag->i == 0)
		size->compt = 0;
	else
		ft_putnbr(flag->i, flag);
	if (size->dot <= size->minus)
		ft_isspacefori(flag, i);
	else if (size->dot > size->minus)
		ft_isspacefori(flag, i);
}

void	ft_pre_doti(t_struct *flag, t_here *here, t_size *size)
{
	int	i;
	int	y;

	if (here->exist == 2 && here->exnum && here->exmin)
		size->num = size->minus;
	if (size->dot == 0 && flag->i == 0)
		size->compt = 0;
	i = size->compt;
	if (size->dot > i)
		i = size->dot;
	y = size->zero - i;
	i = size->minus - i;
	if (flag->i < 0)
	{
		size->compt -= 1;
		y += 1;
		if (!(size->zero > size->dot) && size->dot > size->compt)
			i -= 1;
	}
	if (flag->i < 0)
		flag->ret += write(1, "-", 1);
	ft_iszerofori(flag, size->dot - size->compt);
	deal_with_dot(size, flag, i, y);
}
