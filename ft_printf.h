/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:12:16 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/16 20:45:02 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_strlen(char *str);

int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_putnbr_base(unsigned long int n, char *base);

int			ft_print_pointer(void *ptr, char *base);

int			ft_printf(const char *format, ...);
typedef int	(*t_func_ptr)(void *);
#endif
