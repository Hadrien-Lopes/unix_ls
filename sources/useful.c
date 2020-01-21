/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:12:17 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/10 14:12:21 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/useful.h"

int		disp_error(char const *file_name)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(file_name) + 5))))
		return (EXIT_FAILURE);
	ft_strcpy(str, "ls: ");
	ft_strcpy(str + 4, file_name);
	perror(str);
	free(str);
	return (EXIT_SUCCESS);
}

void	free_t_dir(t_dir *list)
{
	t_dir *tmp_list;

	while (list != NULL)
	{
		free(list->name);
		tmp_list = list;
		if (list->next == NULL)
		{
			free(list);
			break ;
		}
		list = list->next;
		free(tmp_list);
	}
}

void	free_sorted_dir(t_sorted_dir *sorted_dir)
{
	t_sorted_files	*tmp_sorted_files;
	t_sorted_folder	*tmp_sorted_folder;

	while (sorted_dir->sorted_files != NULL)
	{
		free(sorted_dir->sorted_files->name);
		tmp_sorted_files = sorted_dir->sorted_files;
		sorted_dir->sorted_files = sorted_dir->sorted_files->next;
		free(tmp_sorted_files);
	}
	while (sorted_dir->sorted_folder != NULL)
	{
		free(sorted_dir->sorted_folder->name);
		tmp_sorted_folder = sorted_dir->sorted_folder;
		sorted_dir->sorted_folder = sorted_dir->sorted_folder->next;
		free(tmp_sorted_folder);
	}
	free(sorted_dir);
}

t_dir	*add_to_list(t_dir *list, char *d_name)
{
	t_dir *new_list;

	if (!(new_list = (t_dir*)malloc(sizeof(t_dir))))
		return (NULL);
	if (!(new_list->name = (char*)malloc(sizeof(char)
		* (ft_strlen(d_name) + 1))))
	{
		free(new_list);
		return (NULL);
	}
	new_list->name = ft_strcpy(new_list->name, d_name);
	new_list->next = NULL;
	new_list->next = NULL;
	if (list == NULL)
		return (new_list);
	else
	{
		new_list->next = list;
		list->previous = new_list;
	}
	return (new_list);
}

char	*add_path(char *path, char *name)
{
	int		i;
	int		j;
	char	*all_path;

	i = 0;
	j = 0;
	if (!(all_path = (char*)malloc(sizeof(char) * (ft_strlen(path)
		+ ft_strlen(name) + 2))))
		return (NULL);
	while (((ft_strcmp(path, "/"))) && (path && path[i]))
	{
		all_path[i] = path[i];
		i++;
	}
	all_path[i] = '/';
	i++;
	while (name && name[j])
	{
		all_path[i] = name[j];
		j++;
		i++;
	}
	all_path[i] = '\0';
	return (all_path);
}
