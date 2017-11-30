/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:00:43 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 19:05:32 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//remember to add the size

void    ft_string(t_print *print, t_flags *flags)
{
	// if (flags->space && flags->width)
	// 	fill(flags, print, ' ');
	// else if (flags->space)
	// {
	// 	ft_putchar(' ');
	// 	print->ret++;
	// }
	print->data.str = va_arg(print->ap, char *);
	print->ret += ft_strlen(print->data.str);
	ft_putstr(print->data.str);
	// if (flags->space && flags->width)
	// 	fill(flags, print, ' ');
	return ;
}

void    ft_char(t_print *print, t_flags *flags)
{
	print->data.c = va_arg(print->ap, int);
	ft_putchar(print->data.c);
	print->ret += 1;
	return ;
}

void    ft_octal(t_print *print, t_flags *flags)
{
	// char *c = va_arg(print->ap, char *);
	// //ft_putstr(c);
	// print->data.i = ft_hextoi(c);//va_arg(print->ap, char *), 8);
	// ft_putnbr(print->data.i);
	// print->ret += ft_intlen(print->data.i);
	return ;
}

//not working
void    ft_unsigned_int(t_print *print, t_flags *flags) //not working with min int 0x80000000
{
	print->data.i = va_arg(print->ap, int);
	if (print->data.i < 0)
		print->data.i *= -1;
	//printf(print->data.str);
	//if (ft_strcmp(print->data.str, "0x80000000") == 0)
	//	print->data.i == 2147483648;
	// if (print->data.i == -2147483648)
	// 	print->data.i == 2147483648;
	ft_putnbr(print->data.i);
	print->ret += ft_intlen(print->data.i);
	return ;
}

void	ft_l_char(t_print *print, t_flags *flags)
{
	ft_putnbr((int)va_arg(print->ap, wchar_t)); //char that has more than one byte (not correct yet)
	return ;
}
