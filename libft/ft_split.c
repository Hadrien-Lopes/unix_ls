/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:45:47 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/29 11:48:08 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		number_words(char *str)
{
	int i;
	int value;
	int counted;

	i = 0;
	value = 0;
	counted = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			counted = 0;
			i++;
		}
		while (str[i] >= 33 && str[i] <= 126)
		{
			if (counted == 0)
			{
				value++;
				counted = 1;
			}
			i++;
		}
	}
	return (value);
}

static char		*inserting(char *ret_str, int j, int len, char *str)
{
	int cpy;

	cpy = 0;
	if (!(ret_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (str[j] >= 33 && str[j] <= 126)
	{
		ret_str[cpy] = str[j];
		j++;
		cpy++;
	}
	ret_str[cpy] = '\0';
	return (ret_str);
}

static char		**insert(char *str, char **ret_str, int nbr_words)
{
	int i;
	int j;
	int len;
	int nbr;

	i = 0;
	j = 0;
	len = 0;
	nbr = 0;
	while (nbr < nbr_words)
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		j = i;
		while (str[i] >= 33 && str[i] <= 126)
		{
			len++;
			i++;
		}
		ret_str[nbr] = inserting(ret_str[nbr++], j, len, str);
	}
	if (!(ret_str[nbr_words] = (char*)malloc(sizeof(char))))
		return (0);
	ret_str[nbr_words] = 0;
	return (ret_str);
}

char			**ft_split(char *str)
{
	int		nbr_words;
	char	**ret_str;

	nbr_words = number_words(str);
	if (!(ret_str = (char**)malloc(sizeof(char*) * (nbr_words + 1))))
		return (0);
	ret_str = insert(str, ret_str, nbr_words);
	return (ret_str);
}
