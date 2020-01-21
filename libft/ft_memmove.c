/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:35:21 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/19 11:04:52 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		overlap;
	char	*char_dest;
	char	*char_src;

	i = -1;
	overlap = 0;
	char_dest = (char*)dest;
	char_src = (char*)src;
	while (++i < n)
		if (char_src + i == char_dest && i < n)
		{
			overlap = 1;
			break ;
		}
	i = -1;
	if (overlap == 1)
		while (n--)
			char_dest[n] = char_src[n];
	else
		while (++i < n)
			char_dest[i] = char_src[i];
	return (dest);
}
