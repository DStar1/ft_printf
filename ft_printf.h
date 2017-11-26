/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:15:38 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/25 23:09:39 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h> //find out if this is okay for the booleans

typedef struct		s_print
{
	int				ret;
	int				fd;
	char			*fmt;
	va_list			ap;
	va_list			ap2;
}					t_print;

typedef struct		s_flags
{
	bool			hash;
	bool			zero;
	bool			space;
	bool			neg;
	bool			pos;
	bool			perc;
	char			res;
	int				i;
}					t_flags;

typedef struct		s_master
{
	int				i;
	int				j;
	void			*somthing;
	struct s_master	*next;
}					t_master;

int		ft_printf(char *fmt, ...);
void	parse(t_print *ptf);
void	ft_string(t_print *print, t_flags *flags);
void	ft_char(t_print *print, t_flags *flags);
void	ft_int(t_print *print, t_flags *flags);
void	ft_unsigned_int(t_print *print, t_flags *flags);
void	ft_l_char(t_print *print, t_flags *flags);

#endif
