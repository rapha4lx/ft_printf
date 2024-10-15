/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:24:33 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/15 19:44:06 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	call_func(const char **format, ...)
{
	va_list ptr;
	int count;

	count = 0;
	va_start(ptr, format);
	func_ptr f = va_arg(ptr, func_ptr);
	count = (int)f(va_arg(ptr, void*));
	printf("count call_func %d\n", count);
	(*format)++;
	va_end(ptr);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list ptr;
	int	count;

	va_start(ptr, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'c')
			count += call_func(&format, ft_putchar, va_arg(ptr, int));
		else if (*format == '%' && *(format + 1) == 's')
			count += call_func(&format, ft_putstr, va_arg(ptr, char*));
		else if (*format == '%' && *(format + 1) == 'p')
			count += ft_putchar(*format);
		else if (*format == '%' && *(format + 1) == 'd')
		{
			ft_putstr("befero\n");
			count += call_func(&format, ft_putnbr, va_arg(ptr, int));
			ft_putstr("after\n");
		}else if (*format == '%' && *(format + 1) == 'i')
			count += ft_putchar(*format);
		else if (*format == '%' && *(format + 1) == 'u')
			count += ft_putchar(*format);
		else if (*format == '%' && *(format + 1) == 'x')
			count += ft_putchar(*format);
		else if (*format == '%' && *(format + 1) == 'X')
			count += ft_putchar(*format);
		else if (*format == '%' && *(format + 1) == '%')
			count += ft_putchar(*format);
		else if (*format)
			count += ft_putchar(*format);
		format++;
	}
	va_end(ptr);
	return (count);
}
