/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sort_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:08:48 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:10:06 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/argv_sort_files.h"

static	t_sorted_files	*sort_files_rt(t_sorted_dir *dir, t_sorted_files *no)
{
	int				proceed;
	struct stat		buff_1;
	struct stat		buff_2;

	proceed = 1;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_files = no;
		while (dir->sorted_files->next != NULL)
		{
			lstat(dir->sorted_files->name, &buff_1);
			lstat(dir->sorted_files->next->name, &buff_2);
			if (buff_1.st_mtime > buff_2.st_mtime)
				swap_files(dir, &proceed);
			else if (buff_1.st_mtime == buff_2.st_mtime)
			{
				if ((ft_strcmp(dir->sorted_files->name,
					dir->sorted_files->next->name)) < 0)
					swap_files(dir, &proceed);
			}
			dir->sorted_files = dir->sorted_files->next;
		}
	}
	return (no);
}

static	t_sorted_files	*sort_files_t(t_sorted_dir *dir, t_sorted_files *no)
{
	int				proceed;
	struct stat		buff_1;
	struct stat		buff_2;

	proceed = 1;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_files = no;
		while (dir->sorted_files->next != NULL)
		{
			lstat(dir->sorted_files->name, &buff_1);
			lstat(dir->sorted_files->next->name, &buff_2);
			if (buff_1.st_mtime < buff_2.st_mtime)
				swap_files(dir, &proceed);
			else if (buff_1.st_mtime == buff_2.st_mtime)
			{
				if ((ft_strcmp(dir->sorted_files->name,
					dir->sorted_files->next->name)) > 0)
					swap_files(dir, &proceed);
			}
			dir->sorted_files = dir->sorted_files->next;
		}
	}
	return (no);
}

static	t_sorted_files	*sort_files_r(t_sorted_dir *dir)
{
	int				proceed;
	t_sorted_files	*sorted_files_bck;

	proceed = 1;
	sorted_files_bck = dir->sorted_files;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_files = sorted_files_bck;
		while (dir->sorted_files->next != NULL)
		{
			if ((ft_strcmp(dir->sorted_files->name,
				dir->sorted_files->next->name)) < 0)
				swap_files(dir, &proceed);
			dir->sorted_files = dir->sorted_files->next;
		}
	}
	return (sorted_files_bck);
}

static	t_sorted_files	*sort_files(t_sorted_dir *dir)
{
	int				proceed;
	t_sorted_files	*sorted_files_bck;

	proceed = 1;
	sorted_files_bck = dir->sorted_files;
	while (proceed)
	{
		proceed = 0;
		dir->sorted_files = sorted_files_bck;
		while (dir->sorted_files->next != NULL)
		{
			if ((ft_strcmp(dir->sorted_files->name,
				dir->sorted_files->next->name)) > 0)
				swap_files(dir, &proceed);
			dir->sorted_files = dir->sorted_files->next;
		}
	}
	return (sorted_files_bck);
}

t_sorted_files			*sort_files_master(t_sorted_dir *dir, int tab[NBR])
{
	t_sorted_files	*sorted_files_bck;

	sorted_files_bck = dir->sorted_files;
	if (dir->sorted_files == NULL || dir->sorted_files->next == NULL)
		return (sorted_files_bck);
	if (tab[4] == 1 && tab[3] == 1)
		return (sort_files_rt(dir, sorted_files_bck));
	else if (tab[4] == 1 && tab[3] == 0)
		return (sort_files_t(dir, sorted_files_bck));
	else if (tab[4] == 0 && tab[3] == 1)
		return (sort_files_r(dir));
	else if (tab[4] == 0 && tab[3] == 0)
		return (sort_files(dir));
	return (sorted_files_bck);
}
