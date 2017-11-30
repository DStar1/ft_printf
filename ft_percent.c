/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:43:55 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 20:54:56 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

void    ft_percent(t_print *print, t_flags *flags)
{
	flags->intlen = 1;
	if (flags->width)
	{
		if (flags->neg)
		{
			ft_putchar('%');
			fill(flags, print, ' ');
		}
		else
		{
			fill(flags, print, ' ');
			ft_putchar('%');
		}
	}
	else
	{
		ft_putchar('%');
	}
	IFELSE((flags->width == 0), print->ret += flags->intlen, print->ret += flags->width);
}