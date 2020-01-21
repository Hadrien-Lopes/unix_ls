/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:35:10 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/14 10:53:14 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dest_char;
	const char	*src_char;

	dest_char = (char*)dest;
	src_char = (const char*)src;
	while (n--)
	{
		*dest_char = *src_char;
		dest_char++;
		if (*src_char == (char)c)
			return ((void*)dest_char);
		src_char++;
	}
	return (NULL);
}
