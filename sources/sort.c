/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:12:05 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:12:41 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort.h"

t_sorted_files	*file(t_sorted_dir *sorted_dir, const char *name)
{
	t_sorted_files *sorted_files;

	sorted_files = NULL;
	if (!(sorted_files = (t_sorted_files*)malloc(sizeof(t_sorted_files))))
	{
		free_sorted_dir(sorted_dir);
		return (NULL);
	}
	if (!(sorted_files->name = (char*)malloc(sizeof(char) * ft_strlen(name))))
	{
		free_sorted_dir(sorted_dir);
		return (NULL);
	}
	sorted_files->name = ft_strcpy(sorted_files->name, name);
	sorted_files->next = sorted_dir->sorted_files;
	sorted_files->previous = NULL;
	if (sorted_dir->sorted_files != NULL)
		sorted_dir->sorted_files->previous = sorted_files;
	return (sorted_files);
}

t_sorted_folder	*folder(t_sorted_dir *sorted_dir, const char *name)
{
	t_sorted_folder *sorted_folder;

	sorted_folder = NULL;
	if (!(sorted_folder = (t_sorted_folder*)malloc(sizeof(t_sorted_folder))))
	{
		free_sorted_dir(sorted_dir);
		return (NULL);
	}
	if (!(sorted_folder->name = (char*)malloc(sizeof(char) * ft_strlen(name))))
	{
		free_sorted_dir(sorted_dir);
		return (NULL);
	}
	sorted_folder->name = ft_strcpy(sorted_folder->name, name);
	sorted_folder->next = sorted_dir->sorted_folder;
	sorted_folder->previous = NULL;
	if (sorted_dir->sorted_folder != NULL)
		sorted_dir->sorted_folder->previous = sorted_folder;
	return (sorted_folder);
}

static	t_dir	*sort_list(t_dir *list)
{
	int		proceed;
	char	*name_temp;
	t_dir	*list_bck;

	proceed = 1;
	list_bck = list;
	if (list == NULL || list->next == NULL)
		return (list_bck);
	while (proceed)
	{
		proceed = 0;
		list = list_bck;
		while (list->next != NULL)
		{
			if (((ft_strcmp(list->name, list->next->name)) > 0))
			{
				name_temp = list->name;
				list->name = list->next->name;
				list->next->name = name_temp;
				proceed = 1;
			}
			list = list->next;
		}
	}
	return (list_bck);
}

int				parse_argv(t_dir *list, int tab[NBR],
	t_dir *list_bck, t_sorted_dir *s_dir)
{
	struct stat	buff;

	while (list != NULL)
	{
		if ((lstat(list->name, &buff)) == -1)
		{
			if ((disp_error(list->name)) == EXIT_FAILURE)
				norme(list_bck);
			list = list->next;
			continue ;
		}
		if (tab[6] == 1)
		{
			if ((s_dir->sorted_files = file(s_dir, list->name)) == NULL)
				return (norme(list_bck));
		}
		else if ((pls(list, tab, list_bck, s_dir)))
			return (1);
		list = list->next;
	}
	return (0);
}

t_sorted_dir	*sort_argv(char const *argv[], int file_pos,
	t_sorted_dir *s_dir, int tab_option[NBR])
{
	int			i;
	t_dir		*list;
	t_dir		*list_bck;

	i = file_pos - 1;
	list = NULL;
	s_dir->sorted_files = NULL;
	s_dir->sorted_folder = NULL;
	check_all_files(argv, i);
	while (argv[++i])
		list = add_to_list(list, (char*)argv[i]);
	list_bck = list;
	list = sort_list(list);
	if ((parse_argv(list, tab_option, list_bck, s_dir)))
		return (NULL);
	s_dir->sorted_files = sort_files_master(s_dir, tab_option);
	s_dir->sorted_folder = sort_folder_master(s_dir, tab_option);
	free_t_dir(list_bck);
	return (s_dir);
}
