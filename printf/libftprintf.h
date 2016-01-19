/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:26:03 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/19 22:20:27 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <wchar.h>
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
	int	flaglong; // l
	int flaglonglong; // ll
	int flagmax; // j
	int flagshort; // h
	int flagchar; // hh
	int sizze; // z
}	sdp_list;

char		gnt(char *format);
char		*ft_longlongbase(unsigned long long n, unsigned int base);
char		*ft_longbase(unsigned long n, unsigned int base);
void		more_checks(char *format, va_list ap, sdp_list *stock);
char		*ft_itoabaseprintf(unsigned int n , int base);
char		get_next_type(char*format);
int			check_format(char *format, va_list ap, sdp_list *stock);
int			test_du_zero(va_list(ap));
int			return_flags(const char *apply, va_list ap);
int			check_precision(const char *format, va_list ap);
int			return_i(va_list ap, sdp_list *stock);
int			return_longi(va_list ap, sdp_list *stock);
int			return_longlongi(va_list ap, sdp_list *stock);
int			return_maxi(va_list ap, sdp_list *stock);
int			return_s(va_list ap, sdp_list *stock);
int			return_C(va_list ap, sdp_list *stock);
int			return_c(va_list ap, sdp_list *stock);
int			return_i(va_list ap, sdp_list *stock);
int			ft_is_a_flag(const char *format);
int			ft_printf(const char *format, ...);
int			check_diese(sdp_list *stock);
int			return_base(va_list ap,sdp_list *stock, int base, int maj);
int			return_long_base(va_list ap,sdp_list *stock, unsigned int base, int maj);
int			return_long_long_base(va_list ap,sdp_list *stock, unsigned int base, int maj);
int			check_my_format(const char* format, va_list ap);
int			check_space(const char* format, va_list ap);
int			return_unsigned_long(va_list ap, size_t size);
char		*ft_itoabase_max(unsigned int n, int base);
char		*ft_itoabase_long_max(unsigned long n, int base);
char		*ft_itoabase_long_long_max(unsigned long long n, int base);
int			return_unsigned(va_list ap, size_t size);
int			return_long(va_list ap, size_t size);
int			return_string(va_list ap);
int			return_base_max(va_list ap, int base, size_t size);
int			ft_is_convert(const char *format);
int			return_int(va_list ap, size_t size);
const char*	move_to_next_ap(const char *format, int check);
#endif
