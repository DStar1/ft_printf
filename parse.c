/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:05:59 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 18:38:08 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_functs(t_print *ptf, t_flags *flags)
{
	//check_flags(flags); pass all flags to everyone
	((flags->res == 's') || (flags->res == 'S')) ? ft_string(ptf, flags)/*printf("String\n")*/ : 0;							//finished?
	((flags->res == 'd') || (flags->res == 'i')) ? ft_int(ptf, flags)/*printf("int\n")*/ : 0;								//finished?
	(flags->res == 'D') ? printf("i/d with l mod\n") : 0;																	//unfinished
	(flags->res == 'p') ? printf("void * pointer printed in hex same as '%#x'\n") : 0;										//unfinished
	(flags->res == 'o') ? ft_octal(ptf, flags)/*printf("octal\n")*/ : 0;													//unfinished
	(flags->res == 'O') ? printf("o with l mod\n") : 0;																		//unfinished
	(flags->res == 'u') ? ft_unsigned_int(ptf, flags)/*printf("unsigned int\n")*/ : 0; 										//unfinished
	(flags->res == 'U') ? printf("u with l mod\n") : 0;																		//unfinished
	(flags->res == 'x') ? ft_hex(ptf, flags, 0)/*printf("hex lower case\n")*/ : 0; //ft_itoa_base(16) lowercase;										//working on
	(flags->res == 'X') ? ft_hex(ptf, flags, 1)/*printf("hex upper case\n")*/ : 0; //ft_itoa_base(16) capital;										//working on
	(flags->res == 'c') ? ft_char(ptf, flags)/*printf("int converted to char\n")*/ : 0;										//finished
	(flags->res == 'C') ? ft_l_char(ptf, flags)/*printf("c with l mod\n")*/ : 0;
	(flags->res == '%') ? printf("perc with width\n") : 0;											//unfinished
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
	flags->width = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->j = 0;
	flags->z = 0;
	//flags->i = 0;
}

//void			check_flag()

void			set_width(t_flags *flags, t_print *ptf)
{
	int start;

	start = ptf->i;
	while (ptf->fmt[ptf->i] && ft_isdigit(ptf->fmt[ptf->i]))
	{
		flags->width += (ptf->fmt[ptf->i] - '0');
		flags->width *= 10;
		ptf->i++;
	}
	if (ptf->i > start)
		flags->width /= 10;
	return ;
}



//add all flags before identifier
int	check_flags(t_flags *flags, t_print *ptf)
{
	if (ptf->fmt[ptf->i] == '#' || ptf->fmt[ptf->i] == '+' ||
		ptf->fmt[ptf->i] == '-' || ptf->fmt[ptf->i] == '0' ||
		ptf->fmt[ptf->i] == ' ')
		return 1;
	if (ptf->fmt[ptf->i] == 'l' || ptf->fmt[ptf->i] == 'h' ||
		ptf->fmt[ptf->i] == 'j' || ptf->fmt[ptf->i] == 'z')
		return 1;
	return (0);
}

void			parse(t_print *ptf, t_flags *flags)
{
	int		j;
	int		mod;

	j = 1;
	mod = 1;
	set_flags(flags);
	ptf->i++;
	while (ptf->fmt[ptf->i] && (check_flags(flags, ptf)))
	{
		//all in order starting from 1
		IF(ptf->fmt[ptf->i] == '#', flags->hash = j++);
		IF(ptf->fmt[ptf->i] == '+', flags->pos = j++);
		IF(ptf->fmt[ptf->i] == '-', flags->neg = j++);
		IF(ptf->fmt[ptf->i] == '0', flags->zero = j++);
		IF(ptf->fmt[ptf->i] == ' ', flags->space = j++);
		//all_flags(flags, 1);
		IF(ptf->fmt[ptf->i] == 'l', flags->l = mod++);
		IFYZ(ptf->fmt[ptf->i] == 'l' && mod, (flags->l = 0), (flags->ll = 1));
		IF(ptf->fmt[ptf->i] == 'h', flags->h = mod++);
		IFYZ(ptf->fmt[ptf->i] == 'h' && mod, (flags->h = 0), (flags->hh = 1));
		IF(ptf->fmt[ptf->i] == 'j', flags->j = mod++);
		IF(ptf->fmt[ptf->i] == 'z', flags->z = mod++);

		//printf("flag = %c perc = %d\n", ptf->fmt[ptf->i], flags->space);
		ptf->i++;
	}
	(ptf->fmt[ptf->i] && ft_isdigit(ptf->fmt[ptf->i])) ? set_width(flags, ptf) : 0;
	if (ptf->fmt[ptf->i])
	{
		flags->res = ptf->fmt[ptf->i];
		ptf->i++;
	}
	apply_functs(ptf, flags);
	return ;
}