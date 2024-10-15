/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:40:23 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/15 19:38:53 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	number_count(int n, long int *i)
{
	int	count;
	long int	number;

	count = 0;
	number = n;
	if (n == 0)
		return (1);
	if (number < 0)
	{
		count++;
		number = -number;
	}
	*i = number;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long int	i;
	char	*buff;
	int	buff_size;
	int	count;

	i = 0;
	buff_size = number_count(n, &i);
	count = 0;
	if (i == 0)
	{
		ft_putchar(48);
		return (1);
	}
	buff = (char*)malloc(sizeof(char) * buff_size + 1);
	if (buff == NULL)
		return (0);
	while (i != 0)
	{
		//buff[count] = (i / 10) + 48;
		buff[buff_size - 1 - count] = (i % 10) + 48;
		count++;
		i /= 10;
	}
	if (n < 0)
		buff[0] = '-';
	buff[buff_size] = '\0';
	ft_putstr(buff);
	free(buff);
	return (buff_size);
}

