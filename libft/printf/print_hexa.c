/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:43:05 by lumaret           #+#    #+#             */
/*   Updated: 2024/08/21 17:37:28 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_printhexa(unsigned int num, int isUpper)
{
	char	*charlist;

	if (isUpper)
		charlist = "0123456789ABCDEF";
	else
		charlist = "0123456789abcdef";
	if (num >= 16)
	{
		ft_printhexa(num / 16, isUpper);
		ft_printhexa(num % 16, isUpper);
	}
	else if (num <= 9)
		ft_putchar_printf(num + '0', 1);
	else
		ft_putchar_printf(charlist[num], 1);
}

int	ft_puthexa(unsigned int num, int isUpper)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_printhexa(num, isUpper);
	return (ft_hexalen(num));
}
