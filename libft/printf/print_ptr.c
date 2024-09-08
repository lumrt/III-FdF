/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:33:51 by lumaret           #+#    #+#             */
/*   Updated: 2024/08/27 18:14:34 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_printptr(num / 16);
		ft_printptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_printf((num + '0'), 1);
		else
			ft_putchar_printf((num - 10 + 'a'), 1);
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
		print_length += ft_putstr("(nil)");
	else
	{
		print_length += ft_putstr("0x");
		ft_printptr(ptr);
		print_length += ft_hexalen(ptr);
	}
	return (print_length);
}
