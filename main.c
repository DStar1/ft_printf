/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:26:06 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/26 20:51:26 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i = 0;
	int f = ft_printf("my name is %0#- s and I am years old!\n", "Harrison", "0x80");
	ft_putnbr(f);
	//printf("\n%u\n", 0x80000000);
	//ft_hextoi("80");
	printf("\n%o\n", 0x80);
	//printf("\n%d\n", printf("yo %s yo", "hello", "hello", "hello"));
		//ft_printf("my name is %s and I am someone that %C like!", "Harrison", L'β');
	return (0);
}
