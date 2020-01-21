/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:12:45 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:12:47 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_files.h"

static int	lstat_all(struct stat *b1, struct stat *b2, char *path, t_dir *lt)
{
	char	*all_current_path;
	char	*all_next_path;

	if (!(all_current_path = add_path(path, lt->name)))
		return (1);
	if (!(all_next_path = add_path(path, lt->next->name)))
	{
		free(all_current_path);
		return (1);
	}
	lstat(all_current_path, b1);
	lstat(all_next_path, b2);
	free(all_current_path);
	free(all_next_path);
	return (0);
}

static void	swap_sort(t_dir *list, int *proceed)
{
	char	*name_temp;

	name_temp = list->name;
	list->name = list->next->name;
	list->next->name = name_temp;
	*proceed = 1;
}

t_dir		*sort_rt(t_dir *list, char *path)
{
	struct stat	buff_1;
	struct stat	buff_2;
	int			proceed;
	t_dir		*list_bck;

	proceed = 1;
	list_bck = list;
	while (proceed)
	{
		proceed = 0;
		list = list_bck;
		while (list->next != NULL)
		{
			if ((lstat_all(&buff_1, &buff_2, path, list)))
				return (NULL);
			if (buff_1.st_mtime > buff_2.st_mtime)
				swap_sort(list, &proceed);
			else if ((buff_1.st_mtime == buff_2.st_mtime)
				&& (ft_strcmp(list->name, list->next->name)) < 0)
				swap_sort(list, &proceed);
			list = list->next;
		}
	}
	return (list_bck);
}

t_dir		*sort_t(t_dir *list, char *path)
{
	struct stat	buff_1;
	struct stat	buff_2;
	int			proceed;
	t_dir		*list_bck;

	proceed = 1;
	list_bck = list;
	while (proceed)
	{
		proceed = 0;
		list = list_bck;
		while (list->next != NULL)
		{
			if ((lstat_all(&buff_1, &buff_2, path, list)))
				return (NULL);
			if (buff_1.st_mtime < buff_2.st_mtime)
				swap_sort(list, &proceed);
			else if ((buff_1.st_mtime == buff_2.st_mtime)
				&& (ft_strcmp(list->name, list->next->name)) > 0)
				swap_sort(list, &proceed);
			list = list->next;
		}
	}
	return (list_bck);
}

t_dir		*sort(t_dir *list, int tab_options[NBR])
{
	int		proceed;
	t_dir	*list_bck;

	proceed = 1;
	list_bck = list;
	while (proceed)
	{
		proceed = 0;
		list = list_bck;
		while (list->next != NULL)
		{
			if (tab_options[3] == 0)
			{
				if ((ft_strcmp(list->name, list->next->name)) > 0)
					swap_sort(list, &proceed);
			}
			else
			{
				if ((ft_strcmp(list->name, list->next->name)) < 0)
					swap_sort(list, &proceed);
			}
			list = list->next;
		}
	}
	return (list_bck);
}
