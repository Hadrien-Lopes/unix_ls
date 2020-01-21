/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:17:39 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/15 15:13:45 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	nbr_digit(long n)
{
	long nbr;

	nbr = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		nbr++;
	}
	return (nbr);
}

static	long	is_negative(long n)
{
	if (n >= 0)
		return (0);
	return (1);
}

static	char	*reverse(char *str)
{
	long	i;
	long	len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[0] == '-')
		i++;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	long	i;
	long	len;
	long	n_long;
	char	*str;
	int		n2;

	i = 0;
	n_long = (long)n;
	len = nbr_digit(n_long) + is_negative(n_long);
	if (len == 0)
		len = 1;
	if ((n2 = is_negative(n_long)))
		n_long *= -1;
	if (!(str = (char*)malloc(sizeof(char) * (len + is_negative(n_long) + 1))))
		return (NULL);
	if (n2 && n_long != 0)
		str[i++] = '-';
	while (i < len)
	{
		str[i++] = (n_long % 10) + '0';
		n_long /= 10;
	}
	str[i] = '\0';
	str = reverse(str);
	return (str);
}
