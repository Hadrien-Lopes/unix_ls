/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:12:29 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:12:30 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/recursive_option.h"

static int	recursive_block_1(t_dir **list_1, int tab_options[NBR], char *name)
{
	DIR				*dir_1;
	struct dirent	*dirent_1;

	if (((dir_1 = opendir(name)) == NULL) && errno != 0)
	{
		if ((disp_error(name)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	while ((dirent_1 = readdir(dir_1)))
	{
		if (dirent_1->d_name[0] != '.' || tab_options[1] == 1)
			if (!(*list_1 = add_to_list(*list_1, dirent_1->d_name)))
			{
				free_t_dir(*list_1);
				closedir(dir_1);
				return (EXIT_FAILURE);
			}
	}
	closedir(dir_1);
	return (EXIT_SUCCESS);
}

static int	recursive_block_2(t_dir *l, int tab[NBR], char *nm, t_dir *lb)
{
	DIR				*dir_2;
	char			all_path[2048];
	struct stat		lbuff;
	int				flag_error;

	while (lb != NULL)
	{
		if ((flag_error = check_file_for_recursive(nm, lb, l, all_path)) == 0)
			if ((dir_2 = opendir(all_path)))
			{
				lstat(all_path, &lbuff);
				if (!(S_ISLNK(lbuff.st_mode)))
				{
					ft_printf("\n");
					recursive(all_path, tab, 1);
				}
				closedir(dir_2);
			}
		if (flag_error == 2 || flag_error == 3)
			return (EXIT_FAILURE);
		lb = lb->next;
	}
	return (EXIT_SUCCESS);
}

static int	recursive_block_3(t_dir *list, int tab[NBR], char *na, t_dir *bck)
{
	while (list != NULL)
	{
		if (tab[2] == 1)
		{
			if ((list_option(na, &list, tab)))
			{
				free_t_dir(bck);
				return (EXIT_FAILURE);
			}
			else
				break ;
		}
		else
			ft_printf("%s\n", list->name);
		list = list->next;
	}
	return (EXIT_SUCCESS);
}

int			recursive(char *name, int tab_options[NBR], int nbr_arg)
{
	t_dir	*list_1;
	t_dir	*list_1_bck;
	int		flag;

	list_1 = NULL;
	flag = 0;
	if ((recursive_block_1(&list_1, tab_options, name)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	list_1_bck = sort_master(list_1, tab_options, name, &flag);
	if (flag == 1)
	{
		free_t_dir(list_1);
		return (EXIT_FAILURE);
	}
	if (nbr_arg)
		ft_printf("%s:\n", name);
	if ((recursive_block_3(list_1, tab_options, name, list_1_bck)) ==
		EXIT_FAILURE)
		return (EXIT_FAILURE);
	list_1 = list_1_bck;
	if ((recursive_block_2(list_1, tab_options, name, list_1_bck)) ==
		EXIT_FAILURE)
		return (EXIT_FAILURE);
	free_t_dir(list_1);
	return (EXIT_SUCCESS);
}
