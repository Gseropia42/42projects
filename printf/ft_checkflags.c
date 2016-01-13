/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:57:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/13 21:36:14 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*int return_digit(const char *format, va_list ap, char motif)
  {
  int i;
  int size;
  char *temp;

  temp = NULL;
  size = 0;
  i = 0;
  if (*format == '0')
  return_digit(format, ap, '0');
  i = ft_atoi(format);
  while (ft_isdigit(format))
  format++;
  temp = move_to_next_ap(apply, 0);
  if (temp = 's')
  size = ft_strlen(va_arg(ap , char*));
  else if (temp = 'u')
  size = ft_strlen(va_arg(ap, unsigned int));
  else 
  size = ft_strlen(va_arg(ap, int));
  while (i-- > ft_strlen
  */
int check_diese(const char *format, va_list ap)
{
	const char *temp;
 
	temp = move_to_next_ap(format, 0);
	if (*temp == 'o' || *temp == 'O' || *temp == 'X' || *temp == 'x')
	{
		if (test_du_zero(ap) == 0)
			return(0);
		write(1, "0", 1);
		if (*temp == 'X' || *temp == 'x')
			write(1, format, 1);
		if (*temp == 'x')
			return(2 + return_base(ap, 16, 0));
		if (*temp == 'X')
			return(2 + return_base_max(ap, 16, 0));
		return(1 + return_base(ap, 8, 0));
	}
	else
		return(check_my_format(format, ap));
}
int check_pre_str(const char *format, va_list ap, size_t i)
{
	int ret;
	char *stock;

	ret = 0;
	stock = (va_arg(ap, char*));
	while (i-- > 0 && *stock != '\0')
	{
		write(1, stock++, 1);
		ret++;
	}
	return (ret);
}

int check_precision(const char *format, va_list ap)
{
	const char *temp;
	int i;

	i = ft_atoi(format);
	temp = move_to_next_ap(format, 0);
	if (*temp == 's')
		return(check_pre_str(++format, ap, i));
	else if (*temp == 'i' || *temp == 'd')
		return(return_int(ap, i));
	return (0);
}
int check_space(const char *format, va_list ap)
{
	const char *temp;
	va_list ap2;
	int p;

	p = 0;
	va_copy(ap2, ap);
	temp = move_to_next_ap(format, 0);
	while (*format == ' ')
		format++;
	if (*temp == 'd' || *temp == 'i')
	{
		if((p = va_arg(ap2, int)) > -1)
		{
			write(1, " ", 1);
			va_end(ap2);
			return(1 + check_my_format(format , ap));
		}
		va_end(ap2);
		return(check_my_format(format , ap));
	}
	return(check_my_format(format, ap));
}
