/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:21:24 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/14 11:37:26 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	long_n;
	int		is_negative;
	int		digit;

	long_n = (long)n;
	is_negative = 0;
	if (long_n < 0)
	{
		long_n *= -1;
		is_negative = 1;
	}
	if (long_n >= 0)
	{
		if (is_negative == 1)
			ft_putchar('-');
		digit = long_n % 10;
		long_n /= 10;
		if (long_n > 0)
			ft_putnbr((int)long_n);
		ft_putchar(digit + 48);
	}
}
