/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_print_upx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:58:36 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/15 15:16:48 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_base(const char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	ft_putpoint(unsigned long nbr, const char *base, t_struct *flag)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (nbr == 0)
		flag->ret += write(1, "0", 1);
	else
	{
		if (check_base(base))
		{
			while (base[size_base])
				size_base++;
			while (nbr)
			{
				nbr_final[i] = nbr % size_base;
				nbr = nbr / size_base;
				i++;
			}
			while (--i >= 0)
				flag->ret += write(1, &base[nbr_final[i]], 1);
		}
	}
}

void	upzero(const char *base, unsigned int nbr, t_struct *flag, int i)
{
	int	size_base;
	int	nbr_fl[100];

	size_base = 0;
	if (check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_fl[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			flag->ret += write(1, &base[nbr_fl[i]], 1);
	}
}

void	ft_putnbr_base(unsigned int nbr, const char *str, t_struct *flag)
{
	int			i;
	const char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (str[flag->save] == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0)
		flag->ret += write(1, "0", 1);
	else
		upzero(base, nbr, flag, i);
}
