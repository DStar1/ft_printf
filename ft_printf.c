/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:24:34 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 21:55:32 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** man 3 printf
** http://en.cppreference.com/w/cpp/io/c/fprintf
** https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
**
** Modifiers
** hh: signed char
** h: short
** l: long
** ll: long long
** j: intmax_t(d, i)   uintmax_t(o, u, x, X)
** z: signed size_t
** Identifiers
** s: print str ft_putstr()
** S: s with l modifier
** p: print hex 
** d: digit (use va_arg(read, convert/cast)) ex: va_arg(d, long long)
** D: same as d?
** i: same as d?
** o: octal integer
** O: l modifier with o
** u: unsigned int
** U: l modifier with u
** x: hex integer lower case
** X: hex capital
** c: int converted to unsigned char, char is written
** C: c with 1 modifier wchar
** %%: no args?
** FLAGS
** #: 
** 0: field padded with 0's
** -: left justify
** +: right justify
** ' ': positive values begin with blank
** Minimum field width:
** precision: 
** 
*/

//watch oiut for something that has a 0 flag, but shouldn't print out any 0's
void	fill(t_flags *flags, t_print *ptf, char c)
{
	int i;
	//char c;
	int nb;

	i = 0;
	nb = 0;
	//c = ' ';
	if (!flags->neg && flags->zero > flags->neg) //sort the priority here
		c = '0';
	while (i < flags->width - flags->intlen)
	{
		write(1, &c, 1);
		flags->len++;
		i++;
	}
	return ;
}

int		ft_printf(char *fmt, ...)
{
	t_print ptf;
	t_flags	flags;

	ptf.ret = 0;
	ptf.fd = 1;
	ptf.fmt = (char*)fmt;
	va_start(ptf.ap, fmt);
	ptf.i = 0;
	while (ptf.fmt[ptf.i])
	{
		if (ptf.fmt[ptf.i] != '%')
		{
			ft_putchar((ptf.fmt[ptf.i]));
			ptf.ret++;
		}
		else
		{
			parse(&ptf, &flags);
			// if (ptf.fmt[ptf.i + 1] && (ptf.fmt[ptf.i + 1] == '%'))
			// {
			// 	if (neg)
			// 	write(1, &ptf.fmt[ptf.i], 1);
			// 	ptf.i += 2;
			// 	ptf.ret += 2;
			// }
			// else
			// {
			// 	parse(&ptf, &flags);
			// 	//(ptf.fmt[ptf.i + 2]) ? ptf.ret += 1 : 0;
			// }
		}
		if (!ptf.fmt[ptf.i])
			break ;
		ptf.i++;
	}
	//printf("\n%d, res = %c\n", flags.zn, flags.res);
	va_end(ptf.ap);
	return (ptf.ret);
}
