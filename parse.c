/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:05:59 by hasmith           #+#    #+#             */
/*   Updated: 2017/12/03 18:55:58 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_functs(t_print *ptf, t_flags *flags)
{
	//check_flags(flags); pass all flags to everyone
	((flags->res == 's') || (flags->res == 'S')) ? ft_string(ptf, flags) : 0;							//finished?
	((flags->res == 'd') || (flags->res == 'i')) ? ft_int(ptf, flags) : 0;								//finished?
	(flags->res == 'D') ? printf("i/d with l mod\n") : 0;																	//unfinished
	(flags->res == 'p') ? printf("void * pointer printed in hex same as '%#x'\n") : 0;										//unfinished
	(flags->res == 'o') ? ft_oct(ptf, flags, 0) : 0;													//unfinished
	(flags->res == 'O') ? printf("o with l mod\n") : 0;																		//unfinished
	(flags->res == 'u') ? ft_unsigned_int(ptf, flags) : 0; 										//unfinished
	(flags->res == 'U') ? ft_unsigned_int(ptf, flags)/*printf("u with l mod\n")*/ : 0;																		//unfinished
	(flags->res == 'x') ? ft_hex(ptf, flags, 0) : 0; //ft_itoa_base(16) lowercase;			//almost
	(flags->res == 'X') ? ft_hex(ptf, flags, 1) : 0; //ft_itoa_base(16) capital;				//almost
	(flags->res == 'c') ? ft_char(ptf, flags) : 0;										//finished
	(flags->res == 'C') ? ft_l_char(ptf, flags)/*printf("c with l mod\n")*/ : 0;
	(flags->res == '%') ? ft_percent(ptf, flags) : 0;										//finished
	//printf("flags: %d, %d, %d, %d, %d, %d\n", flags->perc, flags->hash, flags->neg, flags->pos, flags->space, flags->zero);
	//printf("%d", printf("%#x", "hello"));
}

static void		set_flags(t_flags *flags)
{
	flags->hash = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->neg = 0;
	flags->pos = 0;
	flags->perc = 0;
	flags->width = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->j = 0;
	flags->z = 0;
	flags->p = 0;
	flags->p1 = 0;
	flags->p2 = 0;
	flags->intlen = 0;
	//flags->i = 0;
}

//void			check_flag()

int			pf_atoi(t_flags *flags, t_print *ptf)
{
	int start;
	int nb;

	nb = 0;
	start = ptf->i;
	while (ptf->fmt[ptf->i] && ft_isdigit(ptf->fmt[ptf->i]))
	{
		nb += (ptf->fmt[ptf->i] - '0');
		nb *= 10;
		ptf->i++;
	}
	if (ptf->i > start)
		nb /= 10;
	return (nb);
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


int		res_flags(t_flags *flags, t_print *print)
{
	if ((flags->res == 's') || (flags->res == 'S'))
		return (1);
	else if ((flags->res == 'd') || (flags->res == 'i') || (flags->res == 'D')
	|| (flags->res == 'o') || (flags->res == 'O') || (flags->res == 'u')
	|| (flags->res == 'U'))
		return (2);
	else if ((flags->res == 'x') || (flags->res == 'X'))
		return (3);
	else if ((flags->res == 'p') || (flags->res == 'c') || (flags->res == 'C')
	|| (flags->res == '%'))
		return (4);
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
		if (ptf->fmt[ptf->i] == 'l' && mod == 1)
			flags->l = mod++;
		else if (ptf->fmt[ptf->i] == 'l' && mod == 2)
		BRACKETS((flags->l = 0), (flags->ll = 1));
		if (ptf->fmt[ptf->i] == 'h' && mod == 1)
			flags->h = mod++;
		else if (ptf->fmt[ptf->i] == 'h' && mod == 2)
		BRACKETS((flags->h = 0), (flags->hh = 1));
		IF(ptf->fmt[ptf->i] == 'j', flags->j = mod++);
		IF(ptf->fmt[ptf->i] == 'z', flags->z = mod++);
		//printf("flag = %c perc = %d\n", ptf->fmt[ptf->i], flags->space);
		ptf->i++;
	}

		//set p2 to the width if it is an int
	if ((ptf->fmt[ptf->i]))// && ft_isdigit(ptf->fmt[ptf->i])) || ptf->fmt[ptf->i] == '.')
	{
		//if (ft_isdigit(ptf->fmt[ptf->i])) && ptf->fmt[ptf->i + 1] != '.')
		if (ptf->fmt[ptf->i] && ft_isdigit(ptf->fmt[ptf->i]))
			flags->width = pf_atoi(flags, ptf);
		// if (ptf->fmt[ptf->i] && ptf->fmt[ptf->i + 1] && ft_isdigit(ptf->fmt[ptf->i]) && ptf->fmt[ptf->i + 1] == '.')
		// 	flags->p1 = pf_atoi(flags, ptf);
		if (ptf->fmt[ptf->i] && ptf->fmt[ptf->i + 1] && ft_isdigit(ptf->fmt[ptf->i + 1]) && ptf->fmt[ptf->i] == '.')
			BRACKETS(ptf->i++, (flags->p = 1) && (flags->p2 = pf_atoi(flags, ptf)));
			//printf("\n\nptf->i:%d, p2:%d char:%c\n\n", ptf->i, flags->p2, ptf->fmt[ptf->i]);
		IF(ptf->fmt[ptf->i] && ptf->fmt[ptf->i] == '.', (flags->p = 1 && ptf->i++));
		//IF(flags->p == 1 && flags->p2 == 0), 
		// if (ptf->fmt[ptf->i] && ft_isdigit(ptf->fmt[ptf->i]))
		// 	flags->width = pf_atoi(flags, ptf);
	}
	//printf("\norder:%d, p:%d, p1:%d, p2:%d\n", ptf->i, flags->p, flags->p1, flags->p2);
	if (ptf->fmt[ptf->i])
	{
		flags->res = ptf->fmt[ptf->i];
		// if ((flags->res != 'o' && !flags->hash))
		// {
			// if (ptf->fmt[ptf->i] && !flags->width && flags->p == 1 && flags->p2 == 0)
			// 	;
			// else if (ptf->fmt[ptf->i] && !flags->width && flags->p == 1 && flags->p2 == 0)
			// 	;
			// else if (ptf->fmt[ptf->i] && flags->p == 1 && !flags->width && flags->p2 == 0)
			// 	;
			// else if (ptf->fmt[ptf->i] && flags->p == 1 && flags->width && flags->p2 == 0)
			// {

			// 	fill(flags, ptf, ' '); //fill_space(flags, ptf, ' ', flags->width);
			// 	ptf->ret += flags->width;
			// }
		// }
		// else 



		// if (res_flags(flags, ptf) == 2) // digits
		// {

		// }
		// if (res_flags(flags, ptf) == 1) //strings
		// else 
		if (ptf->fmt[ptf->i])
			apply_functs(ptf, flags);
	}
	
	return ;
}