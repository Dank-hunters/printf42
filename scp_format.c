/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_format.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:35:36 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:15:33 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_format(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	if (here->exzero)
		ft_iszerofori(flag, size->zero - size->compt);
	if (here->exdot == 1 && size->dot <= size->compt)
		size->compt = size->dot;
	if (here->exnum && here->exmin != 1)
		ft_isspace(str, flag, size, size->num);
	ft_putstrn(flag->s, flag, size->compt);
	if (here->exmin)
		ft_isspace(str, flag, size, size->minus);
}

void	c_format(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	if (here->exdot == 1 && size->dot <= size->compt)
		size->compt = size->dot;
	if (here->exnum && here->exmin != 1)
		ft_isspace(str, flag, size, size->num);
	ft_putchar((char)flag->c, flag);
	if (here->exmin)
		ft_isspace(str, flag, size, size->minus);
}

void	p_format(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	if (here->exdot && size->dot > size->num)
	{
		flag->ret += write(1, "0x", 2);
		ft_iszerofori(flag, size->dot - size->compt);
		ft_putpoint(flag->p, "0123456789abcdef", flag);
	}
	else
	{
		if (size->dot == 0 && here->exdot == 1 && flag->p == 0)
			size->num += 1;
		if (here->exnum && here->exmin != 1)
			ft_isspace(str, flag, size, size->num);
		if (here->exdot && size->dot == 0 && flag->p == 0)
			flag->ret += write(1, "0x", 2);
		else
		{
			flag->ret += write(1, "0x", 2);
			ft_putpoint(flag->p, "0123456789abcdef", flag);
		}
		if (here->exmin)
			ft_isspace(str, flag, size, size->minus);
	}
}
