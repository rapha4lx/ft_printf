/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:31:43 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/15 19:34:54 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void)
{
	long int i = 0;

	printf("number_count: %d test: %d\n", number_count(0, &i), 0);
	printf("number_count: %d test: %d\n", number_count(42, &i), 42);
	printf("number_count: %d test: %d\n", number_count(-42, &i), -42);
	printf("number_count: %d test: %ld\n", number_count(-2147483648, &i), -2147483648);

	ft_putchar('\n');
	ft_putchar('\n');
	
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(-42);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	
	ft_putchar('\n');
	ft_putchar('\n');

	ft_printf("%d\n", 10);
}
