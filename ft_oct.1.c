/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:53:44 by hasmith           #+#    #+#             */
/*   Updated: 2017/12/02 20:41:29 by hasmith          ###   ########.fr       */
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

void	fill_space(t_print *print, t_flags *flags, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
}

void	ft_oct(t_print *print, t_flags *flags, int cap)
{
	flags->intlen = 0;
	oct_data(print, flags);
	//ft_puthex(9223372036854775807, print, cap);
	//print->data.i = va_arg(print->ap, uintmax_t);
	ft_octlen(print->data.super_u, flags);
	
	(flags->p2 > flags->width) ? flags->width = flags->p2 : 0;
	(flags->intlen > flags->width) ? flags->width = flags->intlen : 0;
int tmp = flags->width;
	//IF(print->data.super_u, flags->zero = 0);
	IF(flags->neg, flags->zero = 0);
	if (flags->neg || flags->zero)
	{
		if (flags->p2) //added
		{
			if (flags->p2 > flags->intlen)
				fill_space(print, flags, '0', flags->p2 - flags->intlen);
			ft_putoct(print->data.super_u, print, cap);
			(flags->intlen < flags->width) ? fill_space(print, flags, ' ', flags->width - flags->p2) : 0;
		}
		else
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
	}
	else
	{
		if (flags->p2) //added
		{
			(flags->intlen < flags->width) ? fill_space(print, flags, ' ', flags->width - flags->p2) : 0;
			if (flags->p2 > flags->intlen)
				fill_space(print, flags, '0', flags->p2 - flags->intlen);
			ft_putoct(print->data.super_u, print, cap);
			
		}
		else
		{
			(flags->hash && print->data.super_u != 0) ? flags->intlen++ : 0;
			fill(flags, print, ' ');
			if (flags->hash && print->data.super_u != 0)
				ft_putchar('0');
			ft_putoct(print->data.super_u, print, cap);
		}
	}
	flags->width = tmp;
	IF(flags->width < flags->intlen, flags->width = flags->intlen);

	IFELSE((flags->width == 0), print->ret += flags->intlen, print->ret += flags->width);
}