/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:23:51 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/14 11:38:31 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
			ft_putchar_fd('-', fd);
		digit = long_n % 10;
		long_n /= 10;
		if (long_n > 0)
			ft_putnbr_fd((int)long_n, fd);
		ft_putchar_fd(digit + 48, fd);
	}
}
