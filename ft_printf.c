/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:24:34 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/25 19:51:37 by hasmith          ###   ########.fr       */
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
** C: c with 1 modifier
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

int		ft_printf(char *fmt, ...)
{
	t_print ptf;

	ptf.ret = 0;
	ptf.fd = 1;
	ptf.fmt = (char*)fmt;
	va_start(ptf.ap, fmt);
	parse(&ptf);
//	va_copy(ap2, ap);

	va_end(ptf.ap);
	return (ptf.ret);
}
