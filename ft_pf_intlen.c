/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_intlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 01:06:30 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/30 16:44:26 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Counts the length of an int
*/

#include "ft_printf.h"

int		ft_pf_intlen(uintmax_t n)
{
	uintmax_t	len;

	if (n == 0)
		return (1);
	len = (n < 0) ? 1 : 0;
	if (n == -9223372036854775808)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
