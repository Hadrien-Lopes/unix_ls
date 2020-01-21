/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sort_folder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:08:57 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:10:47 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/argv_sort_folder.h"

static	t_sorted_folder	*sort_folder_rt(t_sorted_dir *dir, t_sorted_folder *no)
{
	int				proceed;
	struct stat		buff_1;
	struct stat		buff_2;

	proceed = 1;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_folder = no;
		while (dir->sorted_folder->next != NULL)
		{
			lstat(dir->sorted_folder->name, &buff_1);
			lstat(dir->sorted_folder->next->name, &buff_2);
			if (buff_1.st_mtime > buff_2.st_mtime)
				swap_folder(dir, &proceed);
			else if (buff_1.st_mtime == buff_2.st_mtime)
			{
				if ((ft_strcmp(dir->sorted_folder->name,
					dir->sorted_folder->next->name)) < 0)
					swap_folder(dir, &proceed);
			}
			dir->sorted_folder = dir->sorted_folder->next;
		}
	}
	return (no);
}

static	t_sorted_folder	*sort_folder_t(t_sorted_dir *dir, t_sorted_folder *no)
{
	int				proceed;
	struct stat		buff_1;
	struct stat		buff_2;

	proceed = 1;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_folder = no;
		while (dir->sorted_folder->next != NULL)
		{
			lstat(dir->sorted_folder->name, &buff_1);
			lstat(dir->sorted_folder->next->name, &buff_2);
			if (buff_1.st_mtime < buff_2.st_mtime)
				swap_folder(dir, &proceed);
			else if (buff_1.st_mtime == buff_2.st_mtime)
			{
				if ((ft_strcmp(dir->sorted_folder->name,
					dir->sorted_folder->next->name)) > 0)
					swap_folder(dir, &proceed);
			}
			dir->sorted_folder = dir->sorted_folder->next;
		}
	}
	return (no);
}

static	t_sorted_folder	*sort_folder_r(t_sorted_dir *dir)
{
	int				proceed;
	t_sorted_folder	*sorted_folder_bck;

	proceed = 1;
	sorted_folder_bck = dir->sorted_folder;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_folder = sorted_folder_bck;
		while (dir->sorted_folder->next != NULL)
		{
			if ((ft_strcmp(dir->sorted_folder->name,
				dir->sorted_folder->next->name)) < 0)
				swap_folder(dir, &proceed);
			dir->sorted_folder = dir->sorted_folder->next;
		}
	}
	return (sorted_folder_bck);
}

static	t_sorted_folder	*sort_folder(t_sorted_dir *dir)
{
	int				proceed;
	t_sorted_folder	*sorted_folder_bck;

	proceed = 1;
	sorted_folder_bck = dir->sorted_folder;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_folder = sorted_folder_bck;
		while (dir->sorted_folder->next != NULL)
		{
			if ((ft_strcmp(dir->sorted_folder->name,
				dir->sorted_folder->next->name)) > 0)
				swap_folder(dir, &proceed);
			dir->sorted_folder = dir->sorted_folder->next;
		}
	}
	return (sorted_folder_bck);
}

t_sorted_folder			*sort_folder_master(t_sorted_dir *dir, int tab[NBR])
{
	t_sorted_folder	*sorted_folder_bck;

	sorted_folder_bck = dir->sorted_folder;
	if (dir->sorted_folder == NULL || dir->sorted_folder->next == NULL)
		return (sorted_folder_bck);
	if (tab[4] == 1 && tab[3] == 1)
		return (sort_folder_rt(dir, sorted_folder_bck));
	else if (tab[4] == 1 && tab[3] == 0)
		return (sort_folder_t(dir, sorted_folder_bck));
	else if (tab[4] == 0 && tab[3] == 1)
		return (sort_folder_r(dir));
	else if (tab[4] == 0 && tab[3] == 0)
		return (sort_folder(dir));
	return (sorted_folder_bck);
}
