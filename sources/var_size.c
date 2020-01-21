/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:12:56 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:12:57 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/var_size.h"

static int	biggest_inode(char *path, t_dir *list)
{
	struct stat	buff;
	int			temp;
	int			temp_len;
	char		*all_path;

	temp = 0;
	temp_len = 0;
	while (list != NULL)
	{
		if (!(all_path = add_path(path, list->name)))
			return (-1);
		lstat(all_path, &buff);
		if (buff.st_nlink > temp)
			temp = buff.st_nlink;
		list = list->next;
		free(all_path);
	}
	while (temp > 0)
	{
		temp /= 10;
		temp_len++;
	}
	return (temp_len);
}

static int	biggest_uid(char *path, t_dir *list)
{
	struct stat		buff;
	size_t			temp_len;
	char			*all_path;
	struct passwd	*uid;

	temp_len = 0;
	while (list != NULL)
	{
		if (!(all_path = add_path(path, list->name)))
			return (-1);
		lstat(all_path, &buff);
		if ((uid = getpwuid((&buff)->st_uid)) != 0)
			if (ft_strlen(uid->pw_name) > temp_len)
				temp_len = ft_strlen(uid->pw_name);
		list = list->next;
		free(all_path);
	}
	return (temp_len);
}

static int	biggest_gid(char *path, t_dir *list)
{
	struct stat		buff;
	size_t			temp_len;
	char			*all_path;
	struct group	*gid;

	temp_len = 0;
	while (list != NULL)
	{
		if (!(all_path = add_path(path, list->name)))
			return (-1);
		lstat(all_path, &buff);
		if ((gid = getgrgid((&buff)->st_uid)) != 0)
			if (ft_strlen(gid->gr_name) > temp_len)
				temp_len = ft_strlen(gid->gr_name);
		list = list->next;
		free(all_path);
	}
	return (temp_len);
}

static int	biggest_file(char *path, t_dir *list)
{
	struct stat	buff;
	int			temp;
	int			temp_len;
	char		*all_path;

	temp = 0;
	temp_len = 0;
	while (list != NULL)
	{
		if (!(all_path = add_path(path, list->name)))
			return (-1);
		lstat(all_path, &buff);
		if (buff.st_size > temp)
			temp = buff.st_size;
		list = list->next;
		free(all_path);
	}
	while (temp > 0)
	{
		temp /= 10;
		temp_len++;
	}
	return (temp_len);
}

int			biggests_var(t_biggest_var *var, char *path, t_dir **list_1)
{
	if ((var->inode = biggest_inode(path, *list_1)) == -1)
		return (EXIT_FAILURE);
	if ((var->file = biggest_file(path, *list_1)) == -1)
		return (EXIT_FAILURE);
	if (var->file == 0)
		var->file = 1;
	if ((var->uid = biggest_uid(path, *list_1)) == -1)
		return (EXIT_FAILURE);
	if ((var->gid = biggest_gid(path, *list_1)) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
