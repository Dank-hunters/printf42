/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compt_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:41:38 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:12:40 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sizeneed(const char *str, t_struct *flag, t_size *size)
{
	if (str[flag->save] == 's')
	{
		if (flag->s == NULL)
			size->compt = 6;
		else
			size->compt = ft_strlen(flag->s);
	}
	else if (str[flag->save] == 'c')
		size->compt = 1;
	else if (str[flag->save] == 'i' || str[flag->save] == 'd')
		size->compt = ft_intsize(flag->i);
	else if (str[flag->save] == 'x')
		size->compt = ft_exasize(flag->x);
	else if (str[flag->save] == 'X')
		size->compt = ft_exasize(flag->x);
	else if (str[flag->save] == 'u')
		size->compt = ft_unsignedsize(flag->u);
	else if (str[flag->save] == 'p')
		size->compt = ft_pointsize(flag->p);
	else if (str[flag->save] == '%')
		size->compt = 1;
}

int	ft_exasize(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	i++;
	return (i);
}

int	ft_unsignedsize(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

int	ft_intsize(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

int	ft_pointsize(unsigned long int nb)
{
	int	i;

	i = 0;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	i++;
	return (i);
}
