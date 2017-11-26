/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:05:59 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/25 20:58:47 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_functs(t_print *ptf, t_flags *flags)
{
	//check_flags(flags); pass all flags to everyone
	((flags->res == 's') || (flags->res == 'S')) ? printf("String\n") : flags->i++; //ft_putstr;
	((flags->res == 'd') || (flags->res == 'i') || (flags->res == 'D')) ? printf("int\n") : flags->i++; //ft_putnbr();
	(flags->res == 'p') ? printf("void * pointer printed in hex same as '%#x'\n") : flags->i++;
	(flags->res == 'o') ? printf("octal\n") : flags->i++;
	(flags->res == 'O') ? printf("o with l mod\n") : flags->i++;
	(flags->res == 'u') ? printf("unsigned int\n") : flags->i++;
	(flags->res == 'U') ? printf("u with l mod\n") : flags->i++;
	(flags->res == 'x') ? printf("hex lower case\n") : flags->i++; //ft_itoa_base(16) lowercase;
	(flags->res == 'X') ? printf("hex upper case\n") : flags->i++; //ft_itoa_base(16) capital;
	(flags->res == 'c') ? printf("int converted to char\n") : flags->i++; //cast to char
	(flags->res == 'C') ? printf("c with l mod\n") : flags->i++;
	(flags->res == '%') ? printf("no args?\n") : flags->i++;
	//printf("flags: %d, %d, %d, %d, %d, %d\n", flags->perc, flags->hash, flags->neg, flags->pos, flags->space, flags->zero);
	//printf("%d", printf("%#x", "hello"));
}

static void		set_flags(t_flags *flags)
{
	flags->hash = false;
	flags->zero = false;
	flags->space = false;
	flags->neg = false;
	flags->pos = false;
	flags->perc = false;
	flags->i = 0;
}

void			parse(t_print *ptf)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (ptf->fmt[i])
	{
		set_flags(&flags);
		if (ptf->fmt[i] == '%' || ptf->fmt[i] == '#' || ptf->fmt[i] == '+' || ptf->fmt[i] == '-' || ptf->fmt[i] == '0')
		{
			while (ptf->fmt[i] && (ptf->fmt[i] == '%' || ptf->fmt[i] == '#' || ptf->fmt[i] == '+' || ptf->fmt[i] == '-' || ptf->fmt[i] == '0' || ptf->fmt[i] == ' '))
			{
				IF(ptf->fmt[i] == '%', flags.perc = true);
				IF(ptf->fmt[i] == '#', flags.hash = true);
				IF(ptf->fmt[i] == '+', flags.pos = true);
				IF(ptf->fmt[i] == '-', flags.neg = true);
				IF(ptf->fmt[i] == '0', flags.zero = true);
				IF(ptf->fmt[i] == ' ', flags.space = true);
				
				//printf("flag = %c\n", ptf->fmt[i]);
				i++;
			}
			if (ptf->fmt[i])
				flags.res = ptf->fmt[i];
			apply_functs(ptf, &flags);
			//printf("res = %c\n", ptf->fmt[i]);
		}
		i++;
	}
	return ;
}