/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:53:44 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 00:01:57 by hasmith          ###   ########.fr       */
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
}

void	ft_hex(t_print *print, t_flags *flags, int cap)
{
	flags->len = 0;
	data(print, flags);
	//print->data.i = va_arg(print->ap, uintmax_t);
	if (flags->neg || flags->zero)
	{
		if (flags->hash)
		{
			ft_putstr("0x");
			flags->len += 2;
		}
		if (flags->zero)
			fill(flags, print, '0');
		ft_puthex(print->data.super_u, print, cap); //add the is capital/double/more
		if (!flags->zero)
			fill(flags, print, ' ');
	}
	else
	{
		fill(flags, print, ' ');
		if (flags->hash)
		{
			ft_putstr("0x");
			flags->len += 2;
		}
		ft_puthex(print->data.super_u, print, cap);
	}
	IFELSE((flags->width == 0), print->ret += flags->len, print->ret += flags->width);
}