/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:45:37 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:16:17 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	if (str[flag->save] == 's')
		s_format(str, flag, size, here);
	else if (str[flag->save] == 'c')
		c_format(str, flag, size, here);
	else if (str[flag->save] == 'i' || str[flag->save] == 'd')
		i_format(str, flag, size, here);
	else if (str[flag->save] == 'x' || str[flag->save] == 'X')
		xX_format(str, flag, size, here);
	else if (str[flag->save] == 'u')
		u_format(str, flag, size, here);
	else if (str[flag->save] == 'p')
		p_format(str, flag, size, here);
	else if (str[flag->save] == '%')
		ft_percent(flag, here, size);
}

void	ft_isspace(const char *str, t_struct *flag, t_size *size, int siz)
{
	if (str[flag->save] == 'p')
		siz -= 2;
	while (siz - size->compt > 0)
	{
		flag->ret += write(1, " ", 1);
		siz--;
	}
}

void	ft_isspacefori(t_struct *flag, int siz)
{
	while (siz > 0)
	{
		flag->ret += write(1, " ", 1);
		siz--;
	}
}

void	ft_iszerofori(t_struct *flag, int siz)
{
	while (siz > 0)
	{
		flag->ret += write(1, "0", 1);
		siz--;
	}
}
