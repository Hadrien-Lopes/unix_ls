/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:37:42 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/19 13:41:59 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t stack;

	i = 0;
	stack = 0;
	if (!ft_strlen(needle))
		return ((char*)haystack);
	while (haystack[i] && len)
	{
		if (haystack[i] == needle[stack])
		{
			stack++;
			if (stack == ft_strlen(needle))
				return (char*)&haystack[i + 1 - ft_strlen(needle)];
			if (haystack[i + 1] != needle[stack])
			{
				i = i - stack + 1;
				len = len + stack - 1;
				stack = 0;
			}
		}
		i++;
		len--;
	}
	return (NULL);
}
