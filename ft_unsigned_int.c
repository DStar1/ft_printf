/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:00:52 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 22:33:10 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_data(t_print *print, t_flags *flags)
{
	if (flags->res == 'U')
		print->data.super_u = va_arg(print->ap, unsigned long);
	else if (flags->h)
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

//not working
void    ft_unsigned_int(t_print *print, t_flags *flags) //add casting for va_args
{
	//print->data.super_u = va_arg(print->ap, uintmax_t);
	u_data(print, flags);
	//IF(flags->res == 'U', print->data.super_u = (unsigned long)print->data.super_u);
	flags->intlen = ft_pf_intlen(print->data.super_u);
	if (flags->width)
	{
		if (flags->neg)
		{
			ft_pf_putnbr(print->data.super_u);
			fill(flags, print, ' ');
		}
		else
		{
			fill(flags, print, ' ');
			ft_pf_putnbr(print->data.super_u);
		}
		IF(flags->intlen > flags->width, flags->width = flags->intlen);
		print->ret += flags->width;
	}
	else
	{
		ft_pf_putnbr(print->data.super_u);
		print->ret += flags->intlen;
	}
}