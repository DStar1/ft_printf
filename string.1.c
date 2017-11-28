/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:00:43 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/28 00:34:13 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill(t_flags *flags, t_print *ptf, int len)
{
	int i;
	char c;
	int nb;

	i = 0;
	nb = 0;
	c = ' ';
	if (!flags->neg && flags->zero > flags->neg) //sort the priority here
		c = '0';
	while (i < flags->width - len)
	{
		write(1, &c, 1);
		//ptf->ret++;
		i++;
	}
	return ;
}

//remember to add the size

void    ft_string(t_print *print, t_flags *flags)
{
	print->data.str = va_arg(print->ap, char *);
	print->ret += ft_strlen(print->data.str);
	ft_putstr(print->data.str);
	return ;
}

void    ft_char(t_print *print, t_flags *flags)
{
	print->data.c = va_arg(print->ap, int);
	ft_putchar(print->data.c);
	print->ret += 1;
	return ;
}

void    ft_int(t_print *print, t_flags *flags)
{
	int len;
	int nlen;
	int neg;

	neg = 0;
	nlen = 0;
	print->data.i = va_arg(print->ap, int);
	IF(print->data.i < 0, neg = -1);
	if (neg == -1 && flags->space == 0) //manipulate these for changes
	{
		len++;
		print->data.i *= -1;
		neg = -1;
		flags->width--;
		ft_putchar('-');
	}
	else if (flags->pos > 0 && print->data.i >= 0 && flags->space == 0) //manipulate these for changes
	{
		len++;
		ft_putchar('+');
		flags->width--;
	}
	len = ft_intlen(print->data.i);
	(flags->neg == 0) ? fill(flags, print, len) : 0;
	if (neg == -1 && flags->space > 0) //manipulate these for changes
	{
		len++;
		flags->width--;
		ft_putchar('-');
	}
	else if (flags->pos > 0 && flags->space > 0) //manipulate these for changes
	{
		len++;
		ft_putchar('+');
		flags->width--;
	}
	ft_putnbr(print->data.i);
	//flags->width -= nlen;
	(flags->neg > 0) ? fill(flags, print, len) : 0;
	IFELSE((flags->width == 0), print->ret += len, print->ret += flags->width + 1); //add 2 to account for spaces added (maybe not right)
	//print->ret += flags->width;// + 2;
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
