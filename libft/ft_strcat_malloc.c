/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:16:29 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/29 11:16:31 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_malloc(char *str, char *buff)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (!(new_str = (char*)malloc(sizeof(char) * (ft_strlen(str) +
		BUFF_SIZE + 1))))
		return (0);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buff[j])
	{
		new_str[i] = buff[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
