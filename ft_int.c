/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:00:03 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 18:21:43 by hasmith          ###   ########.fr       */
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

void    ft_int(t_print *print, t_flags *flags)
{
	int neg;

	flags->len = 0;
	neg = 1;
    flags->intlen = 0;
	int_data(print, flags);
	//print->data.super = va_arg(print->ap, int);

	if (print->data.super < 0)
	{
		print->data.super *= -1;
		neg = -1;
		flags->intlen = 1;
	}
	if (neg == -1 && flags->zero) //manipulate these for changes
		ft_putchar('-');
	else if (flags->pos && flags->zero)//&& flags->space == 0) //manipulate these for changes
	{
		ft_putchar('+');
		flags->intlen++;
	}
	flags->intlen = flags->intlen + ft_pf_intlen(print->data.super);
	(flags->neg == 0) ? fill(flags, print, ' ') : 0;
	if (flags->space && !flags->pos && !flags->zero && neg == 1)
	{
		ft_putchar(' ');
		flags->len++;
	}
	if (neg == -1 && !flags->zero) //manipulate these for changes
		ft_putchar('-');
	else if (flags->pos && !flags->zero) //manipulate these for changes
	{
		ft_putchar('+');
		flags->len++;
	}
	(print->data.super < 0) ? flags->intlen-- : 0;
	ft_pf_putnbr(print->data.super); 															//changed all to this
	//(print->data.super < 0) ? ft_putstr("2147483648") : ft_pf_putnbr(print->data.super);
	(flags->neg > 0) ? fill(flags, print, ' ') : 0;
	IFELSE((flags->width == 0), print->ret += flags->len + flags->intlen, print->ret += flags->width);
	return ;
}