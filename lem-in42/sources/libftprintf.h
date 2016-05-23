/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:26:03 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/17 12:20:00 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <wchar.h>
# include <limits.h>
# include <inttypes.h>

typedef	struct		s_sdp
{
	char			fonction;
	int				flagminus;
	int				flagdiese;
	int				flagzero;
	int				flagplus;
	int				precision;
	long long		prec_size;
	long long		size;
	int				flagspace;
	int				flaglong;
	int				flaglonglong;
	int				flagmax;
	int				flagshort;
	int				flagchar;
	int				sizze;
	int				temp;
}					t_sdp;

long long			ft_longlongatoi(char *s);
int					read_achar(wint_t prout);
int					read_wchar(wchar_t *temp);
int					ft_printf(const char *format, ...);
int					valid_string(wchar_t *string);
void				ft_putw(wchar_t c);
int					ft_wcharlen(wchar_t *c);
void				ft_putwchar(wchar_t *c);
char				*ft_longlongitoa(long long n);
char				*ft_longitoa(long n);
char				*ft_maxtoa(intmax_t n);
char				gnt(char *format, int check);
char				*ft_longlongbase(unsigned long long n, unsigned int base);
char				*ft_longbase(unsigned long n, unsigned int base);
char				*ft_itoabaseprintf(unsigned int n, int base);
int					cf(char *format, va_list ap, t_sdp *stock);
int					return_i(va_list ap, t_sdp *stock);
int					return_longi(va_list ap, t_sdp *stock);
int					return_longlongi(va_list ap, t_sdp *stock);
int					return_maxi(va_list ap, t_sdp *stock);
int					return_long_s(va_list ap, t_sdp *stock);
int					return_s(va_list ap, t_sdp *stock);
int					return_cc(va_list ap, t_sdp *stock);
int					return_c(va_list ap, t_sdp *stock);
int					return_base(va_list ap, t_sdp *s, int base, int maj);
int					llong_base(va_list ap, t_sdp *s, unsigned int b, int maj);
int					maxbase(va_list ap, t_sdp *s, unsigned int base, int maj);
int					long_base(va_list ap, t_sdp *s, unsigned int base, int maj);
char				*ft_itoabase_max(unsigned int n, int base);
char				*ft_itoabase_long_max(unsigned long n, int base);
char				*ft_itoabase_long_long_max(unsigned long long n, int base);
int					get_next_line(int fd, char **line);
#endif
