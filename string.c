/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:00:43 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/25 23:20:01 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//remember to add the size

void    ft_string(t_print *print, t_flags *flags)
{
	print->ret += ft_strlen(va_arg(print->ap, char *));
	ft_putstr(va_arg(print->ap2, char *));
	return ;
}

void    ft_char(t_print *print, t_flags *flags)
{
	ft_putchar(va_arg(print->ap, int));
	va_arg(print->ap2, int);
	print->ret += 1;
	return ;
}

void    ft_int(t_print *print, t_flags *flags)
{
	ft_putnbr(va_arg(print->ap, int));
	va_arg(print->ap2, int);
	return ;
}

void    ft_unsigned_int(t_print *print, t_flags *flags)
{
	
	return ;
}

void	ft_l_char(t_print *print, t_flags *flags)
{
	ft_putnbr((int)va_arg(print->ap, wchar_t)); //char that has more than one byte (not correct yet)
	return ;
}
