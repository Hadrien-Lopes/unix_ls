/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:35:46 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/14 10:54:30 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ucc_s1;
	const unsigned char *ucc_s2;

	ucc_s1 = s1;
	ucc_s2 = s2;
	while (n--)
	{
		if (*ucc_s1 != *ucc_s2)
			return (*ucc_s1 - *ucc_s2);
		ucc_s1++;
		ucc_s2++;
	}
	return (0);
}
