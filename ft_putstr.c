/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:11:41 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/16 20:45:12 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	count;

	if (str == NULL)
		return (ft_putstr("(null)"));
	count = ft_strlen(str);
	write(1, str, count);
	return (count);
}
