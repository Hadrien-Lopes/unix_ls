/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sort_useful.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:09:07 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:11:04 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/argv_sort_useful.h"

void	swap_files(t_sorted_dir *dir, int *proceed)
{
	char	*name_temp;

	name_temp = dir->sorted_files->name;
	dir->sorted_files->name = dir->sorted_files->next->name;
	dir->sorted_files->next->name = name_temp;
	*proceed = 1;
}

void	swap_folder(t_sorted_dir *dir, int *proceed)
{
	char	*name_temp;

	name_temp = dir->sorted_folder->name;
	dir->sorted_folder->name = dir->sorted_folder->next->name;
	dir->sorted_folder->next->name = name_temp;
	*proceed = 1;
}

int		norme(t_dir *list_bck)
{
	free_t_dir(list_bck);
	return (1);
}

int		pls(t_dir *list, int tab[NBR], t_dir *list_bck, t_sorted_dir *s_dir)
{
	struct stat	buff;

	if ((lstat(list->name, &buff)) == -1)
		return (1);
	if ((S_ISLNK(buff.st_mode)))
	{
		if (opendir(list->name) && tab[5] == 1)
		{
			if ((s_dir->sorted_folder = folder(s_dir, list->name)) == NULL)
				return (norme(list_bck));
		}
		else if ((s_dir->sorted_files = file(s_dir, list->name)) == NULL)
			return (norme(list_bck));
	}
	else if ((S_ISDIR(buff.st_mode)))
	{
		if ((s_dir->sorted_folder = folder(s_dir, list->name)) == NULL)
			return (norme(list_bck));
	}
	else if ((s_dir->sorted_files = file(s_dir, list->name)) == NULL)
		return (norme(list_bck));
	return (0);
}

void	check_all_files(char const *argv[], int i)
{
	struct stat buff;

	while (argv[++i])
	{
		if ((lstat(argv[i], &buff)) == -1)
		{
			if (errno == ENOENT)
			{
				if ((ft_strlen(argv[i]) == 0))
				{
					disp_error("fts_open");
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}
