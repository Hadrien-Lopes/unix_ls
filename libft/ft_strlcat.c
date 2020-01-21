/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:36:59 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/14 11:42:41 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_tmp;
	const char	*src_tmp;
	size_t		i;
	size_t		len;

	dst_tmp = dst;
	src_tmp = src;
	i = size;
	while (i-- != 0 && *dst_tmp != '\0')
		dst_tmp++;
	len = dst_tmp - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(src_tmp));
	while (*src_tmp != '\0')
	{
		if (i != 1)
		{
			*dst_tmp++ = *src_tmp;
			i--;
		}
		src_tmp++;
	}
	*dst_tmp = '\0';
	return (len + (src_tmp - src));
}
