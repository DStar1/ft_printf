/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:12:57 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/29 16:32:03 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_puthex(uintmax_t nb, t_print *print, int cap)
{
	if (nb < 16 && cap == 0)
	{
		ft_putchar(HEX[nb]);
		//print->ret++;
	}
	else if (nb < 16 && cap == 1)
	{
		ft_putchar(HEX[nb + 16]);
		//print->ret++;
	}
	else
	{
		ft_puthex(nb / 16, print, cap);
		ft_puthex(nb % 16, print, cap);
	}
}

void    ft_hexlen(uintmax_t nb, t_flags *flags)
{
	if (nb < 16)
		flags->intlen++;
	else
	{
		ft_hexlen(nb / 16, flags);
		ft_hexlen(nb % 16, flags);
	}
}