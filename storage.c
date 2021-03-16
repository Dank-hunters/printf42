/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:30:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:15:11 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_storage(const char *str, t_struct *flag)
{
	flag->save = flag->index;
	while (str[flag->save] && ((str[flag->save] != 's') && (str[flag->save] != 'c') && \
				(str[flag->save] != 'x') && (str[flag->save] != 'u') && \
				(str[flag->save] != 'X') && (str[flag->save] != 'i') && \
				(str[flag->save] != 'd') && (str[flag->save] != 'p') && \
				(str[flag->save] != '%')))
		flag->save++;
	if (str[flag->save] == 's')
		flag->s = va_arg(flag->vargs, char *);
	if (str[flag->save] == 'c' )
		flag->c = va_arg(flag->vargs, int);
	if (str[flag->save] == 'i' || str[flag->save] == 'd')
		flag->i = va_arg(flag->vargs, int);
	if (str[flag->save] == 'u' )
		flag->u = va_arg(flag->vargs, unsigned int);
	if (str[flag->save] == 'x' )
		flag->x = va_arg(flag->vargs, unsigned int);
	if (str[flag->save] == 'X' )
		flag->x = va_arg(flag->vargs, unsigned int);
	if (str[flag->save] == 'p' )
		flag->p = va_arg(flag->vargs, unsigned long int);
	if (str[flag->save] == '%')
		flag->percent = '%';
}

void	take_size(const	char *str, t_struct *flag, t_size *size, t_here *here)
{
	size->i = flag->index;
	while (str[size->i] && str[size->i] != 's' && str[size->i] != 'c' && str[size->i] != 'u' && \
			str[size->i] != 'i' && str[size->i] != 'd' && str[size->i] != 'p' && \
			str[size->i] != 'x' && str[size->i] != 'X' && str[size->i] != '%')
	{
		if (str[size->i] == '*')
			forwith(str, flag, size, here);
		else if (str[size->i] == '0')
			forzero(str, size, here);
		else if (str[size->i] > '0' && str[size->i] <= '9')
			fornum(str, size, here);
		else if (str[size->i] == '.')
			fordot(str, size, here);
		else if (str[size->i] == '-')
			forminus(str, size, here);
		else
			size->i++;
	}
	here->exist = here->exmin + here->exnum + here->exdot + here->exzero;
	here->exlar = size->minus + size->dot + size->num + size->zero;
}

void	init_struct(t_struct *flag, t_size *size, t_here *here)
{
	here->exmin = 0;
	here->exwith = 0;
	here->exzero = 0;
	here->exdot = 0;
	here->exnum = 0;
	size->dot = 0;
	size->minus = 0;
	size->with = 0;
	size->num = 0;
	size->zero = 0;
	size->compt = 0;
	flag->c = 0;
}
