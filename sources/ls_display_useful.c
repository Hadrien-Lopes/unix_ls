/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_useful.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:12:10 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:12:12 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls_display_useful.h"

void			ls_disp_files(t_sorted_dir *sorted_dir, int tab_options[NBR])
{
	int flag;

	flag = 0;
	while (sorted_dir->sorted_files != NULL)
	{
		flag = 1;
		if (tab_options[2] == 1)
			list_option_file(sorted_dir->sorted_files->name);
		else
			ft_printf("%s", sorted_dir->sorted_files->name);
		sorted_dir->sorted_files = sorted_dir->sorted_files->next;
		if (sorted_dir->sorted_files != NULL)
			ft_printf("\n");
	}
	if (flag)
	{
		ft_printf("\n");
		if (sorted_dir->sorted_folder != NULL)
			ft_printf("\n");
	}
}

static int		test(t_dir *list_1, int tab[NBR], t_sorted_dir *sd, DIR *dir_1)
{
	int flag_2;

	flag_2 = 0;
	sort_master(list_1, tab, sd->sorted_folder->name, &flag_2);
	if (flag_2 == 1)
	{
		free_t_dir(list_1);
		closedir(dir_1);
		return (EXIT_FAILURE);
	}
	if ((sd->sorted_folder->next != NULL ||
		sd->sorted_folder->previous != NULL) || (errno != 0))
		ft_printf("%s:\n", sd->sorted_folder->name);
	return (EXIT_SUCCESS);
}

static int		test2(t_dir **list_1, int tab[NBR], t_sorted_dir *sd, DIR *dir)
{
	t_dir	*list_1_bck;

	list_1_bck = *list_1;
	while (*list_1 != NULL)
	{
		if (tab[2] == 1)
		{
			if ((list_option(sd->sorted_folder->name, list_1, tab)))
			{
				closedir(dir);
				free_t_dir(list_1_bck);
				return (EXIT_FAILURE);
			}
		}
		else
		{
			ft_printf("%s\n", (*list_1)->name);
			*list_1 = (*list_1)->next;
		}
	}
	return (EXIT_SUCCESS);
}

static int		fckg_test(DIR *dir_1, int tab_options[NBR], t_dir **list_1)
{
	struct dirent	*dirent_1;

	while ((dirent_1 = readdir(dir_1)))
		if (dirent_1->d_name[0] != '.' || tab_options[1] == 1)
			if (!(*list_1 = add_to_list(*list_1, dirent_1->d_name)))
			{
				closedir(dir_1);
				free_t_dir(*list_1);
				return (EXIT_FAILURE);
			}
	return (EXIT_SUCCESS);
}

int				ulti_test(DIR *dir_1, int tab_options[NBR],
	t_sorted_dir *sorted_dir, t_dir *list_1)
{
	t_dir	*list_1_bck;

	if ((fckg_test(dir_1, tab_options, &list_1)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((test(list_1, tab_options, sorted_dir, dir_1)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	list_1_bck = list_1;
	if ((test2(&list_1, tab_options, sorted_dir, dir_1)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	closedir(dir_1);
	sorted_dir->sorted_folder = sorted_dir->sorted_folder->next;
	if (sorted_dir->sorted_folder != NULL)
		ft_printf("\n");
	free_t_dir(list_1_bck);
	return (EXIT_SUCCESS);
}
