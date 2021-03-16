/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_print_ic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:09:04 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/15 15:10:31 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, t_struct *flag)
{
	flag->ret += write(1, &c, 1);
}

void	ft_putstrn(const char *str, t_struct *flag, int u)
{
	int	i;

	i = 0;
	if (!str)
		flag->ret += write(1, "(null)", u);
	else if (u == 0)
		i = u + 1;
	else
	{
		while (str[i] && (i < u))
		{
			flag->ret += write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int nb, t_struct *flag)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		flag->ret += write(1, "2147483648", 10);
	else
	{
		if (nb < 0)
			nb = -nb;
		i = nb % 10 + 48;
		if (nb >= 10)
			ft_putnbr(nb / 10, flag);
		flag->ret += write(1, &i, 1);
	}
}

void 	ft_isunsigned(unsigned int nb, t_struct *flag)
{
	int	i;

	i = 0;
	i = nb % 10 + 48;
	if (nb == 0)
		flag->ret += write(1, "0", 1);
	else
	{
		if (nb >= 10)
			ft_isunsigned(nb / 10, flag);
		flag->ret += write(1, &i, 1);
	}
}
