/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:24:33 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/16 20:52:53 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	call_func(const char **format, ...)
{
	va_list		ptr;
	int			count;
	t_func_ptr	func;

	va_start(ptr, format);
	count = 0;
	func = va_arg(ptr, t_func_ptr);
	count = func(va_arg(ptr, void *));
	(*format)++;
	va_end(ptr);
	return (count);
}

static int	ft_choice(const char **format, va_list ptr)
{
	int	count;

	count = 0;
	if (**format == '%' && *((*format) + 1) == 'c')
		count = call_func(format, &ft_putchar, va_arg(ptr, int));
	else if (**format == '%' && *((*format) + 1) == 'u')
		count = call_func(format, &ft_putnbr_unsigned, va_arg(ptr,
					unsigned int));
	else if (**format == '%' && *((*format) + 1) == 'x')
		count = call_func(format, &ft_putnbr_base, va_arg(ptr, unsigned int),
				"0123456789abcdef");
	else if (**format == '%' && *((*format) + 1) == 'X')
		count = call_func(format, &ft_putnbr_base, va_arg(ptr, unsigned int),
				"0123456789ABCDEF");
	else if (**format == '%' && *((*format) + 1) == '%')
		count = call_func(format, ft_putchar, '%');
	else
		count = ft_putchar(**format);
	(*format)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		count;

	va_start(ptr, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's')
			count += call_func(&format, &ft_putstr, va_arg(ptr, char *));
		else if (*format == '%' && *(format + 1) == 'p')
			count += call_func(&format, &ft_print_pointer, va_arg(ptr, void *),
					"0123456789abcdef");
		else if (*format == '%' && (*(format + 1) == 'd' || *(format
					+ 1) == 'i'))
			count += call_func(&format, &ft_putnbr, va_arg(ptr, int));
		else
		{
			count += ft_choice(&format, ptr);
			continue ;
		}
		format++;
	}
	va_end(ptr);
	return (count);
}
