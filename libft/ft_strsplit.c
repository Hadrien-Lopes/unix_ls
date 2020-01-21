/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:17:25 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/14 11:17:29 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		number_words(const char *s, char c)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if ((s[0] != c))
		nbr++;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && s[i - 1] == c)
			nbr++;
		i++;
	}
	return (nbr);
}

static	char	**alloc_end(int nbr, char **ret_mat, const char *s, char c)
{
	int i;
	int j;
	int tab;

	if (!(ret_mat = (char**)malloc(sizeof(char*) * (nbr + 1))))
		return (NULL);
	i = -1;
	j = 0;
	tab = 0;
	while (s[++i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			j++;
			i++;
		}
		if (j > 0)
		{
			if (!(ret_mat[tab] = (char*)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			tab++;
		}
		j = 0;
	}
	return (ret_mat);
}

static	char	**insert(char **returned_mat, const char *s, char c)
{
	int i;
	int j;
	int tab;

	i = -1;
	j = 0;
	tab = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			returned_mat[tab][j] = s[i];
			j++;
		}
		if ((s[i] == c || s[i + 1] == '\0') && j > 0)
		{
			returned_mat[tab][j] = '\0';
			tab++;
			j = 0;
		}
	}
	returned_mat[tab] = 0;
	return (returned_mat);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nbr;
	char	**returned_mat;

	returned_mat = NULL;
	if (!(s) || !(c))
		return (NULL);
	nbr = number_words(s, c);
	returned_mat = alloc_end(nbr, returned_mat, s, c);
	if (returned_mat == NULL)
		return (NULL);
	returned_mat = insert(returned_mat, s, c);
	return (returned_mat);
}
