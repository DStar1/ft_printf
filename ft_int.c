/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:00:03 by hasmith           #+#    #+#             */
/*   Updated: 2017/12/01 01:28:55 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_data(t_print *print, t_flags *flags)
{
	print->data.super = va_arg(print->ap, intmax_t);
	if (flags->h)
		print->data.super = (short int)print->data.super;
	else if (flags->hh)
		print->data.super = (char)print->data.super;
	else if (flags->l)
		print->data.super = (long int)print->data.super;
	else if (flags->ll)
		print->data.super = (long long int)print->data.super;
	else if (flags->j)
		print->data.super = (intmax_t)print->data.super;
	else if (flags->z)
		print->data.super = (size_t)print->data.super;
	else
		print->data.super = (int)print->data.super;
}

void	p_fill(t_print *print, t_flags *flags, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < flags->width - flags->intlen)
	{
		write(1, &c, 1);
		flags->len++;
		i++;
	}
	return ;
}

void	fill_p2(t_flags *flags, t_print *print)
{
	int i;

	i = 0;
	while (i < flags->p2 - flags->intlen)
	{
		ft_putchar('0');
		i++;
	}
}

void    ft_int(t_print *print, t_flags *flags)
{
	int neg;

	flags->len = 0;
	neg = 1;
    flags->intlen = 0;
	int_data(print, flags);
	//(flags->p2) ? flags->zero = 0 : 0; //take out to get different result
	if (print->data.super < 0)
	{
		print->data.super *= -1;
		neg = -1;
		flags->intlen = 1;
		//(flags->p2 < flags->width) ? flags->intlen = 1 : 0;
	}
	(flags->pos && neg != -1) ? flags->intlen+=2 : 0;
	flags->intlen = flags->intlen + ft_pf_intlen(print->data.super);
	// int tmp = flags->intlen;
	// (flags->p2 > flags->intlen) ? flags->intlen += (flags->width - flags->p2) : 0;

	IF(flags->width && flags->p2 > flags->width && neg == -1, flags->intlen--);
	IF(flags->width && (flags->p2 > flags->width), (flags->width = flags->p2 && flags->zero++));
	
	if (neg == -1 && flags->zero) //manipulate these for changes
		ft_putchar('-');
	else if (flags->pos && flags->zero)//&& flags->space == 0) //manipulate these for changes
	{
		ft_putchar('+');
		flags->intlen++;
		//(flags->p2 < flags->intlen) ? flags->intlen++ : 0;
	}
	int intlen = flags->intlen;
	(flags->p2 > flags->intlen) ? flags->intlen = flags->p2 : 0;
	(flags->neg == 0) ? fill(flags, print, ' ') : 0;
	(flags->p2 > intlen) ? flags->intlen = intlen : 0;
	if (flags->space && !flags->pos && !flags->zero && neg == 1)
	{
		if (flags->p2 < flags->intlen)
		{
			ft_putchar(' ');
			flags->len++;
		}
	}
	if (neg == -1 && !flags->zero) //manipulate these for changes
		ft_putchar('-');
	else if (flags->pos && !flags->zero) //manipulate these for changes
	{
		ft_putchar('+');
		//flags->len++;
		(flags->p2 < flags->intlen) ? flags->len++ : 0;
	}
	(flags->pos && neg != -1) ? flags->intlen-=2 : 0;
	((flags->p2 > flags->width && neg == -1)) ? (flags->intlen--) : 0;
	(flags->p2) ? fill_p2(flags, print) : 0;
	(print->data.super < 0) ? flags->intlen-- : 0;
	
	//(flags->p2 > tmp) ? flags->intlen = tmp : 0;
	//(flags->p2 > tmp) ? fill(flags, print, '0') : 0;
	//(flags->p2 > tmp) ? flags->intlen = tmp2 : 0;
	ft_pf_putnbr(print->data.super);
	//printf("\nwidth = %d\n", flags->intlen);
	//(print->data.super < 0) ? ft_putstr("2147483648") : ft_pf_putnbr(print->data.super);

	intlen = flags->intlen;
	if (flags->p2 > flags->intlen) 
	{
		flags->intlen = flags->p2;
		(flags->pos) ? flags->intlen++ : 0;
	}
	(flags->neg > 0) ? fill(flags, print, ' ') : 0;
	(flags->p2 > intlen) ? flags->intlen = intlen : 0;
	//printf("\nintlen = %d, width = %d\n", flags->intlen, flags->width);
((flags->p2 > flags->width && neg == -1)) ? (print->ret++) : 0;
//printf("\nintlen = %d, width = %d\n", flags->intlen, flags->width);
	(flags->p2 > flags->width && flags->p2 > flags->intlen) ? flags->width = flags->p2 : 0;
	IFELSE((flags->width == 0), print->ret += flags->len + flags->intlen, print->ret += flags->width);
	//IF((flags->p2 && flags->intlen > flags->p2 && flags->width == 0), print->ret += flags->len + flags->intlen);
	return ;
}