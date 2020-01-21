/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:12:39 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/10 14:12:41 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

t_dir	*sort_master(t_dir *list, int tab_options[NBR], char *path, int *flag)
{
	t_dir	*list_bck;

	list_bck = list;
	if (list == NULL || list->next == NULL)
		return (list_bck);
	if (tab_options[4] == 1 && tab_options[3] == 1)
	{
		if ((sort_rt(list, path)) == NULL)
		{
			*flag = 1;
			return (NULL);
		}
	}
	else if (tab_options[4] == 1 && tab_options[3] == 0)
	{
		if ((sort_t(list, path)) == NULL)
		{
			*flag = 1;
			return (NULL);
		}
	}
	else if (tab_options[4] == 0)
		sort(list, tab_options);
	return (list_bck);
}

int		recursive_control(t_sorted_dir *sd, int tab_options[NBR])
{
	int nbr_arg;

	nbr_arg = 0;
	if (tab_options[0] == 1 && sd->sorted_folder != NULL)
	{
		while (sd->sorted_folder != NULL)
		{
			if (sd->sorted_folder->next != NULL)
				nbr_arg = 1;
			if ((recursive(sd->sorted_folder->name, tab_options, nbr_arg)) ==
				EXIT_FAILURE)
			{
				return (EXIT_FAILURE);
			}
			sd->sorted_folder = sd->sorted_folder->next;
			if (sd->sorted_folder != NULL)
				ft_printf("\n");
		}
	}
	return (EXIT_SUCCESS);
}

int		ls_display(t_sorted_dir *sd, int tab_options[NBR])
{
	DIR		*dir_1;
	t_dir	*list_1;
	t_dir	*list_1_bck;

	list_1 = NULL;
	list_1_bck = list_1;
	ls_disp_files(sd, tab_options);
	if ((recursive_control(sd, tab_options) == EXIT_FAILURE))
		return (EXIT_FAILURE);
	while ((sd->sorted_folder != NULL))
	{
		if (((dir_1 = opendir(sd->sorted_folder->name)) == NULL) && errno != 0)
		{
			if ((disp_error(sd->sorted_folder->name)) == EXIT_FAILURE)
			{
				closedir(dir_1);
				return (EXIT_FAILURE);
			}
			sd->sorted_folder = sd->sorted_folder->next;
			continue ;
		}
		if ((ulti_test(dir_1, tab_options, sd, list_1)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ls_start(int argc, char const *argv[])
{
	int					file_pos;
	int					tab_options[NBR];
	t_sorted_dir		*sorted_dir;
	t_sorted_files		*sorted_files_bck;
	t_sorted_folder		*sorted_folder_bck;

	if (!(sorted_dir = (t_sorted_dir*)malloc(sizeof(t_sorted_dir))))
		exit(EXIT_FAILURE);
	file_pos = init_tab(tab_options, argc, argv);
	if (file_pos == argc)
		init_dir(sorted_dir, tab_options);
	else
		init_dir_argv(sorted_dir, file_pos, argv, tab_options);
	sorted_files_bck = sorted_dir->sorted_files;
	sorted_folder_bck = sorted_dir->sorted_folder;
	if ((ls_display(sorted_dir, tab_options)) == EXIT_FAILURE)
	{
		sorted_dir->sorted_files = sorted_files_bck;
		sorted_dir->sorted_folder = sorted_folder_bck;
		free_sorted_dir(sorted_dir);
		exit(EXIT_FAILURE);
	}
	sorted_dir->sorted_files = sorted_files_bck;
	sorted_dir->sorted_folder = sorted_folder_bck;
	free_sorted_dir(sorted_dir);
}

int		main(int argc, char const *argv[])
{
	ls_start(argc, argv);
	return (EXIT_SUCCESS);
}
