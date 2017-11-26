/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:26:06 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/25 23:23:24 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i = 0;
	int f = ft_printf("my name is %s and I am someone that like!\n", "Harrison", 'b');
	ft_putnbr(f);
	//printf("\n%d\n", printf("yo %s yo", "hello", "hello", "hello"));
		//ft_printf("my name is %s and I am someone that %C like!", "Harrison", L'β');
	return (0);
}
