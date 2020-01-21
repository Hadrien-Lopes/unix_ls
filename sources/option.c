/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:11:52 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/10 14:11:55 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/option.h"

static	void	disp_error_msg(char c)
{
	write(2, "/bin/ls: illegal option -- ", 27);
	write(2, &c, 1);
	write(2, "\nusage: ls ", 11);
	write(2, "[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 52);
	exit(EXIT_FAILURE);
}

static	int		fill_options(char c, int tab_options[NBR])
{
	if (c == 'R')
		tab_options[0] = 1;
	else if (c == 'a')
		tab_options[1] = 1;
	else if (c == 'l')
	{
		tab_options[2] = 1;
		tab_options[5] = 0;
	}
	else if (c == 'r')
		tab_options[3] = 1;
	else if (c == 't')
		tab_options[4] = 1;
	else if (c == '1')
	{
		tab_options[5] = 1;
		tab_options[2] = 0;
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int		fill_options_bonus(char c, int tab_options[NBR])
{
	if (c == 'd')
		tab_options[6] = 1;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	void	search_options(const char *str, int tab_options[NBR])
{
	int i;

	i = 0;
	while (str[++i])
	{
		if ((fill_options(str[i], tab_options)) == EXIT_FAILURE)
		{
			if ((fill_options_bonus(str[i], tab_options)) == EXIT_FAILURE)
			{
				disp_error_msg(str[i]);
			}
		}
		fill_options_bonus(str[i], tab_options);
	}
}

int				parse_option(int argc, char const *argv[], int tab[NBR])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == '\0')
			return (i);
		else if (argv[i][1] == '-')
		{
			if (argv[i][2] == '\0')
				return (i + 1);
			else if (argv[i][2] == '-')
				search_options(argv[i], tab);
			else
				search_options(argv[i], tab);
		}
		else
			search_options(argv[i], tab);
	}
	return (i);
}
