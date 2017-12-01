/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:53:44 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/30 16:44:30 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_data(t_print *print, t_flags *flags)
{
	if (flags->h)
		print->data.super_u = (unsigned int)va_arg(print->ap, unsigned short);
	else if (flags->hh)
		print->data.super_u = (unsigned int)va_arg(print->ap, unsigned char);
	else if (flags->l)
		print->data.super_u = va_arg(print->ap, unsigned long);
	else if (flags->ll)
		print->data.super_u = va_arg(print->ap, unsigned long long);
	else if (flags->j)
		print->data.super_u = va_arg(print->ap, uintmax_t);
	else if (flags->z)
		print->data.super_u = va_arg(print->ap, size_t);
	else
		print->data.super_u = va_arg(print->ap, unsigned int); //possibly change to uintmax_t
}

void	ft_oct(t_print *print, t_flags *flags, int cap)
{
	flags->intlen = 0;
	oct_data(print, flags);
	//ft_puthex(9223372036854775807, print, cap);
	//print->data.i = va_arg(print->ap, uintmax_t);
	ft_octlen(print->data.super_u, flags);
	//IF(print->data.super_u, flags->zero = 0);
	IF(flags->neg, flags->zero = 0);
	if (flags->neg || flags->zero)
	{
		if (flags->hash && print->data.super_u != 0)
		{
			ft_putchar('0');
			flags->intlen++;
		}
		if (flags->zero)
			fill(flags, print, '0');
		ft_putoct(print->data.super_u, print, cap); //add the is capital/double/more
		if (!flags->zero)
			fill(flags, print, ' ');
	}
	else
	{
		(flags->hash && print->data.super_u != 0) ? flags->intlen++ : 0;
		fill(flags, print, ' ');
		if (flags->hash && print->data.super_u != 0)
			ft_putchar('0');
		ft_putoct(print->data.super_u, print, cap);
	}
	IF(flags->width < flags->intlen, flags->width = flags->intlen);

	IFELSE((flags->width == 0), print->ret += flags->intlen, print->ret += flags->width);
}