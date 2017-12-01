/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:07:18 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/30 16:44:18 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_putnbr(uintmax_t n)
{
	// if (n == -9223372036854775808) //possibly make <=
	// 	ft_putstr("-9223372036854775808");
	if (n < 0)
	{
		ft_putchar('-');
		ft_pf_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_pf_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
