/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:37:29 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/15 11:51:25 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t k;
	size_t needle_len;

	i = 0;
	j = 0;
	k = 0;
	needle_len = ft_strlen(needle);
	if (!(needle_len))
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[k++] == needle[j++])
			if (j == needle_len)
				return ((char*)&haystack[k - needle_len]);
		if (j > 0)
		{
			j = 0;
			k = i;
		}
		i++;
		k++;
	}
	return (NULL);
}
