/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:26:03 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/16 20:21:31 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct g_list
{
	char fonction;
	int	flagminus;
	int flagdiese;
	int flagzero;
	int flagplus;
	int precision;
	int prec_size;
	int size;
	int flagspace;
}	sdp_list;


int			test_du_zero(va_list(ap));
int			return_flags(const char *apply, va_list ap);
int			check_precision(const char *format, va_list ap);
int			return_char(va_list ap);
int			ft_is_a_flag(const char *format);
int			ft_printf(const char *format, ...);
int			return_base(va_list ap, int base, size_t size);
int			check_diese(const char *format, va_list ap);
int			check_my_format(const char* format, va_list ap);
int			check_space(const char* format, va_list ap);
char		*ft_itoabase_max(int n, int base);
int			return_unsigned_long(va_list ap, size_t size);
int			return_unsigned(va_list ap, size_t size);
int			return_long(va_list ap, size_t size);
int			return_string(va_list ap);
int			return_base_max(va_list ap, int base, size_t size);
int			ft_is_convert(const char *format);
int			return_int(va_list ap, size_t size);
const char*	move_to_next_ap(const char *format, int check);
#endif
