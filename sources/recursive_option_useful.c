/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_option_useful.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:10:13 by hmoulher          #+#    #+#             */
/*   Updated: 2019/08/16 13:10:17 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/recursive_option_useful.h"

void	add_path_2(char *path, char *name, char all_path[2048])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
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
}

int		check_file_for_recursive(char *na, t_dir *lb, t_dir *l, char ap[2048])
{
	DIR	*dir_2;

	errno = 0;
	if ((ft_strcmp(lb->name, ".")) == 0 || ((ft_strcmp(lb->name, "..")) == 0))
		return (1);
	add_path_2(na, lb->name, ap);
	if ((dir_2 = opendir(ap)) == NULL && errno != ENOTDIR)
	{
		ft_printf("\n%s:\n", ap);
		if ((disp_error(lb->name)) == EXIT_FAILURE)
		{
			closedir(dir_2);
			free_t_dir(l);
			return (3);
		}
	}
	if (dir_2 != NULL)
		closedir(dir_2);
	return (0);
}
