/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:38:30 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/14 11:07:04 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long int	value;
	int				negative;

	value = 0;
	negative = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+')
	{
		nptr++;
		if (!ft_isdigit(*nptr))
			return (0);
	}
	if (*nptr == '-')
	{
		nptr++;
		negative = -1;
	}
	while (ft_isdigit(*nptr))
	{
		value = value * 10 + (*nptr - 48);
		nptr++;
	}
	return (value * negative);
}
