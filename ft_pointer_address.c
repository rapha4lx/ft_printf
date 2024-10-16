/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:27:59 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/16 20:45:09 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr, char *base)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putnbr_base((unsigned long int)ptr, base);
	return (count);
}
