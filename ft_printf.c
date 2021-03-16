/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:33:56 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:13:25 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_justif(const char *str, t_struct *flag, t_size *size, t_here *here)
{
	ft_storage(str, flag);
	ft_sizeneed(str, flag, size);
	ft_print(str, flag, size, here);
	flag->index = flag->save + 1;
}

void	ft_identifier(const char *str, t_struct *flag, t_size *size, \
	   	t_here *here)
{
	while (str[flag->index])
	{
		init_struct(flag, size, here);
		if (str[flag->index] == '%' && str[flag->index + 1] == '%')
		{
			flag->index++;
			flag->ret += write(1, &str[flag->index], 1);
			flag->index++;
		}
		else if (str[flag->index] == '%')
		{
			flag->index++;
			take_size(str, flag, size, here);
			ft_justif(str, flag, size, here);
		}
		while (str[flag->index] && (str[flag->index] != 37))
		{
			flag->ret += write(1, &str[flag->index], 1);
			flag->index++;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	int			i;
	t_struct	flag;
	t_size		size;
	t_here		here;

	i = 0;
	flag.save = 0;
	flag.ret = 0;
	flag.index = 0;
	va_start(flag.vargs, str);
	if (ft_flag_here(str) == 1)
		ft_identifier(str, &flag, &size, &here);
	else if (ft_dontprint(str) == 0)
	{
		while (str[i])
		{
			flag.ret += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(flag.vargs);
	i = flag.ret;
	return (i);
}
