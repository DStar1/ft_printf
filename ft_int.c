/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:00:03 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/28 21:04:38 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_int(t_print *print, t_flags *flags)
{
	int neg;

	flags->len = 0;
	neg = 1;
    flags->intlen = 0;
	print->data.i = va_arg(print->ap, int);

	if (print->data.i < 0)
	{
		print->data.i *= -1;
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
	flags->intlen = flags->intlen + ft_intlen(print->data.i);
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
	(print->data.i < 0) ? flags->intlen-- : 0;
	(print->data.i < 0) ? ft_putstr("2147483648") : ft_putnbr(print->data.i);
	(flags->neg > 0) ? fill(flags, print, ' ') : 0;
	IFELSE((flags->width == 0), print->ret += flags->len + flags->intlen, print->ret += flags->width);
	return ;
}