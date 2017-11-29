/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:26:06 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/28 21:18:24 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// int i = 0;
	// int f = ft_printf("\nmy %% name is %s and I am %#505d years old!\n", "Harrison", 22);
	// printf("\nsingle dig = %d\n", ft_printf("%d", 42));
	// ft_putchar('\n');
	// ft_putnbr(f);
	// ft_putchar('\n');
	// int j = printf("\nmy %% name is %s and I am %#505d years old!\n", "Harrison", 22);
	// ft_putnbr(j);

	// printf("\npos = %d\n", ft_printf("\nmy name %dis and I am %06d years old!\n", -22, 2));
	// printf("\npos = %d\n", printf("\nmy name %dis and I am %06d years old!\n", -22, 2));

	printf("\npos = %d\n", ft_printf("%3d", -4));
	printf("\npos = %d\n", printf("%3d", -4));
	//ft_puthex(-4294967296, 1);
	//printf("\n%u\n", 0x80000000);
	//ft_hextoi("80");
	//printf("\n%o\n", 0x80);
	//printf("\n%d\n", printf("yo %s yo", "hello", "hello", "hello"));
		//ft_printf("my name is %s and I am someone that %C like!", "Harrison", L'β');
		
	// while (1)
	// 	; //leaks check
	return (0);
}
