/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:05:59 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/27 23:10:39 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_functs(t_print *ptf, t_flags *flags)
{
	//check_flags(flags); pass all flags to everyone
	((flags->res == 's') || (flags->res == 'S')) ? ft_string(ptf, flags)/*printf("String\n")*/ : 0;							//finished
	((flags->res == 'd') || (flags->res == 'i')) ? ft_int(ptf, flags)/*printf("int\n")*/ : 0;								//finished
	(flags->res == 'D') ? printf("i/d with l mod\n") : 0;																	//unfinished
	(flags->res == 'p') ? printf("void * pointer printed in hex same as '%#x'\n") : 0;										//unfinished
	(flags->res == 'o') ? ft_octal(ptf, flags)/*printf("octal\n")*/ : 0;													//unfinished
	(flags->res == 'O') ? printf("o with l mod\n") : 0;																		//unfinished
	(flags->res == 'u') ? ft_unsigned_int(ptf, flags)/*printf("unsigned int\n")*/ : 0; 										//unfinished
	(flags->res == 'U') ? printf("u with l mod\n") : 0;																		//unfinished
	(flags->res == 'x') ? printf("hex lower case\n") : 0; //ft_itoa_base(16) lowercase;										//unfinished
	(flags->res == 'X') ? printf("hex upper case\n") : 0; //ft_itoa_base(16) capital;										//unfinished
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
void	before_flags(t_flags *flags, t_print *ptf)
{
	(flags->res == 'd') ? fill(flags, ptf) : 0;
	return ;
}

void			parse(t_print *ptf, t_flags *flags)
{
	int		j;

	j = 1;
	set_flags(flags);
	ptf->i++;
	while (ptf->fmt[ptf->i] && (ptf->fmt[ptf->i] == '#' || ptf->fmt[ptf->i] == '+' || ptf->fmt[ptf->i] == '-' || ptf->fmt[ptf->i] == '0' || ptf->fmt[ptf->i] == ' '))
	{
		//all in order starting from 1
		IF(ptf->fmt[ptf->i] == '#', flags->hash = j++);
		IF(ptf->fmt[ptf->i] == '+', flags->pos = j++);
		IF(ptf->fmt[ptf->i] == '-', flags->neg = j++);
		IF(ptf->fmt[ptf->i] == '0', flags->zero = j++);
		IF(ptf->fmt[ptf->i] == ' ', flags->space = j++);
		//all_flags(flags, 1);

		//printf("flag = %c perc = %d\n", ptf->fmt[ptf->i], flags->space);
		ptf->i++;
	}
	(ptf->fmt[ptf->i] && ft_isdigit(ptf->fmt[ptf->i])) ? set_width(flags, ptf) : 0;
	if (ptf->fmt[ptf->i])
	{
		flags->res = ptf->fmt[ptf->i];
		ptf->i++;
	}
	//before_flags(flags, ptf);
	apply_functs(ptf, flags);
//	after_flags(flags, ptf);
		//ft_printf("num spaces = %d\n", flags->sn);
	//set_flags(flags);
	//printf("res = %c\n", ptf->fmt[ptf->i]);
		//ptf->i++;
	return ;
}