/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_start_useful.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:12:17 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:12:18 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls_start_useful.h"

int			init_tab(int tab_options[NBR], int argc, char const *argv[])
{
	int i;

	i = 0;
	while (i < NBR)
	{
		tab_options[i] = 0;
		i++;
	}
	return (parse_option(argc, argv, tab_options));
}

static void	init_dir_d_on(t_sorted_dir *sd)
{
	if (!(sd->sorted_files =
		(t_sorted_files*)malloc(sizeof(t_sorted_files))))
	{
		free(sd);
		exit(EXIT_FAILURE);
	}
	if (!(sd->sorted_files->name = (char*)malloc(sizeof(char) * 2)))
	{
		free(sd->sorted_files);
		free(sd);
		exit(EXIT_FAILURE);
	}
	sd->sorted_files->name = ft_strcpy(sd->sorted_files->name, ".");
	sd->sorted_files->next = NULL;
	sd->sorted_files->previous = NULL;
	sd->sorted_folder = NULL;
}

static void	init_dir_d_off(t_sorted_dir *sd)
{
	if (!(sd->sorted_folder =
		(t_sorted_folder*)malloc(sizeof(t_sorted_folder))))
	{
		free(sd);
		exit(EXIT_FAILURE);
	}
	if (!(sd->sorted_folder->name = (char*)malloc(sizeof(char) * 2)))
	{
		free(sd->sorted_folder);
		free(sd);
		exit(EXIT_FAILURE);
	}
	sd->sorted_folder->name = ft_strcpy(sd->sorted_folder->name, ".");
	sd->sorted_folder->next = NULL;
	sd->sorted_folder->previous = NULL;
	sd->sorted_files = NULL;
}

void		init_dir(t_sorted_dir *sd, int tab_options[NBR])
{
	if (tab_options[6] == 0)
		init_dir_d_off(sd);
	else
		init_dir_d_on(sd);
}

void		init_dir_argv(t_sorted_dir *sd, int p, const char *v[], int t[NBR])
{
	if ((sd = sort_argv(v, p, sd, t)) == NULL)
	{
		free(sd);
		exit(EXIT_FAILURE);
	}
}
