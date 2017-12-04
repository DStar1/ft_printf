/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:53:44 by hasmith           #+#    #+#             */
/*   Updated: 2017/12/03 17:15:46 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	data(t_print *print, t_flags *flags)
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

void	ft_hex(t_print *print, t_flags *flags, int cap)
{
	flags->intlen = 0;
	data(print, flags);
	//ft_puthex(9223372036854775807, print, cap);
	//print->data.i = va_arg(print->ap, uintmax_t);
	if (check_zero(print, flags, print->data.super_u) != 0)
		return ;
	ft_hexlen(print->data.super_u, flags);
	//IF(print->data.super_u, flags->zero = 0);
	IF(flags->neg, flags->zero = 0);
	if (flags->neg || flags->zero)
	{
		if (flags->hash && print->data.super_u != 0)
		{
			(cap == 0) ? ft_putstr("0x") : ft_putstr("0X");
			flags->intlen += 2;
		}
		if (flags->zero)
			fill(flags, print, '0');
		ft_puthex(print->data.super_u, print, cap); //add the is capital/double/more
		if (!flags->zero)
			fill(flags, print, ' ');
	}
	else
	{
		(flags->hash && print->data.super_u != 0) ? flags->intlen += 2 : 0;
		fill(flags, print, ' ');
		if (flags->hash && print->data.super_u != 0)
			(cap == 0) ? ft_putstr("0x") : ft_putstr("0X");
		ft_puthex(print->data.super_u, print, cap);
	}
	IF(flags->width < flags->intlen, flags->width = flags->intlen);

	IFELSE((flags->width == 0), print->ret += flags->intlen, print->ret += flags->width);
}