/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:32:45 by cguiot            #+#    #+#             */
/*   Updated: 2021/03/16 17:20:17 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_point
{
	va_list				vargs;
	int					index;
	int					save;
	int					ret;
	int					i;
	int					d;
	char				*s;
	int					c;
	char				percent;
	unsigned int		u;
	unsigned int		x;
	unsigned int		xm;
	unsigned long int	p;
}				t_struct;

typedef struct s_here
{
	int	exist;
	int	exlar;
	int	exmin;
	int	exwith;
	int	exdot;
	int	exnum;
	int	exzero;
}				t_here;

typedef struct s_size
{
	int	compt;
	int	dot;
	int	minus;
	int	with;
	int	num;
	int	zero;
	int	i;
}				t_size;

int		ft_printf(const char *str, ...);
void	nodoti(const char *str, t_here *here, t_struct *flag, t_size *size);
void	ft_pre_doti(t_struct *flag, t_here *here, t_size *size);
int		ft_dontprint(const char *str);
void	ft_percent(t_struct *flag, t_here *here, t_size *size);
void	ft_iszerofori(t_struct *flag, int siz);
void	ft_isspacefori(t_struct *flag, int siz);
void	xX_format(const char *str, t_struct *flag, t_size *size, t_here *here);
void	i_format(const char *str, t_struct *flag, t_size *size, t_here *here);
void	u_format(const char *str, t_struct *flag, t_size *size, t_here *here);
void	p_format(const char *str, t_struct *flag, t_size *size, t_here *here);
void	c_format(const char *str, t_struct *flag, t_size *size, t_here *here);
void	s_format(const char *str, t_struct *flag, t_size *size, t_here *here);
void	init_struct(t_struct *flag, t_size *size, t_here *here);
int		ft_flag_here(const char *str);
void	ft_putstrn(const char *str, t_struct *flag, int u);
void	ft_storage(const char *str, t_struct *flag);
void	ft_justif(const char *str, t_struct *flag, t_size *size, t_here *here);
void	ft_identifier(const char *str, t_struct *flag, t_size *size, \
		t_here *here);
void	ft_isspace(const char *str, t_struct *flag, t_size *size, int siz);
void	ft_print(const char *str, t_struct *flag, t_size *size, t_here *here);
void	ft_iszero(t_struct *flag, t_size *size, int siz);
void	ft_flagnum(const char *str, t_struct *flag, t_size *size, t_here *here);
void	ft_flagzero(const char *str, t_struct *flag, t_size *size, \
		t_here *here);
void	ft_flagless(const char *str, t_struct *flag, t_size *size, \
		t_here *here);
void	ft_flagpoint(const char *str, t_struct *flag, t_size *size, \
		t_here *here);
void	forwith(const char *str, t_struct *flag, t_size *size, t_here *here);
int		ft_pointsize(unsigned long int nb);
int		ft_intsize(int nb);
int		ft_unsignedsize(unsigned int nb);
int		ft_exasize(unsigned int nb);
void	ft_sizeneed(const char *str, t_struct *flag, t_size *size);
void	take_size(const	char *str, t_struct *flag, t_size *size, t_here *here);
void	forzero(const char *str, t_size *size, t_here *here);
void	fornum(const char *str, t_size *size, t_here *here);
void	fordot(const char *str, t_size *size, t_here *here);
void	forminus(const char *str, t_size *size, t_here *here);
void	ft_putstr(const char *str, t_struct *flag);
void	ft_putchar(int c, t_struct *flag);
void	ft_putnbr(int nb, t_struct *flag);
void	ft_isunsigned(unsigned int nb, t_struct *flag);
void	ft_putnbr_base(unsigned int nbr, const char *str, t_struct *flag);
void	ft_putpoint(unsigned long nbr, const char *base, t_struct *flag);
int		ft_strlen(const char *str);
int		ft_ischar(char c, char *str);

#endif
