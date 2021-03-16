/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:40:31 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 16:25:22 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nodot(const char *str, t_struct *flag, t_size *size)
{
	int	i;

	i = size->num - size->compt;
	if (!(size->minus > size->num))
		ft_isspace(str, flag, size, i);
	ft_isunsigned(flag->u, flag);
	ft_isspace(str, flag, size, size->minus);
}

void	ft_pre_dot(t_struct *flag, t_size *size)
{
	int	i;
	int	y;

	if (size->dot == 0 && flag->u == 0)
		size->compt = 0;
	i = size->compt;
	if (size->dot > i)
		i = size->dot;
	y = size->zero - i;
	i = size->minus - i;
	ft_iszerofori(flag, size->dot - size->compt);
	if (size->zero > size->dot)
		ft_iszerofori(flag, y);
	if (size->dot == 0 && flag->u == 0)
		size->compt = 0;
	else
		ft_isunsigned(flag->u, flag);
	if (size->dot <= size->minus)
		ft_isspacefori(flag, i);
	else if (size->dot > size->minus)
		ft_isspacefori(flag, i);
}

void	ft_minusabs(t_struct *flag, t_size *size, t_here *here)
{
	int	i;
	int	y;

	if (size->dot == 0 && here->exdot && flag->u == 0)
		size->compt = 0;
	i = size->compt;
	if (size->dot > i)
		i = size->dot;
	y = size->zero - i;
	i = size->num - i;
	if (here->exnum)
		ft_isspacefori(flag, i);
	if (!here->exdot)
	{
		if (here->exzero)
			ft_iszerofori(flag, y);
	}
	else if (here->exdot)
	{
		if (here->exzero)
			ft_isspacefori(flag, y);
		ft_iszerofori(flag, size->dot - size->compt);
	}
	if (!(size->dot == 0 && here->exdot && flag->u == 0))
		ft_isunsigned(flag->u, flag);
}	

void	u_format(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	if (here->exist == 0)
		ft_isunsigned(flag->u, flag);
	if (here->exmin == 1)
	{
		if (!here->exdot)
			nodot(str, flag, size);
		else if (here->exdot)
			ft_pre_dot(flag, size);
	}
	else if (here->exmin == 0 && here->exist > 0)
		ft_minusabs(flag, size, here);
}
