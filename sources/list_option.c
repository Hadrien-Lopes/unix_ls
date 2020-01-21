/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:11:42 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/10 14:11:44 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list_option.h"

void	list_first(char *all_path, t_biggest_var var, struct stat lbuff)
{
	int				speright_flag;
	struct passwd	*uid;
	struct group	*gid;

	speright_flag = permission_master(lbuff, all_path);
	if (speright_flag == 0)
		ft_printf(" %*hu", var.inode + 1, lbuff.st_nlink);
	else
		ft_printf(" %*hu", var.inode, lbuff.st_nlink);
	if ((uid = getpwuid(lbuff.st_uid)) != 0)
		ft_printf(" %-*s", var.uid, uid->pw_name);
	if ((gid = getgrgid(lbuff.st_gid)) != 0)
		ft_printf("  %-*s", var.gid, gid->gr_name);
	if ((S_ISCHR(lbuff.st_mode)) || ((S_ISBLK(lbuff.st_mode))))
		ft_printf(" %d, %d", major(lbuff.st_rdev), minor(lbuff.st_rdev));
	else
		ft_printf(" %*lld", var.file + 1, lbuff.st_size);
}

void	list_second(struct stat lbuff)
{
	struct tm	*time_var;
	time_t		current_time_time_t;
	struct tm	*current_time;
	int			current_months;
	int			current_date;

	current_time_time_t = time(NULL);
	current_time = ft_localtime(&current_time_time_t);
	current_months = (current_time->tm_mon + 1 + (current_time->tm_year * 12));
	current_date = current_time->tm_mday;
	time_var = ft_localtime(&lbuff.st_mtime);
	ft_printf(" %s", disp_mon(time_var->tm_mon));
	ft_printf(" %2.d", time_var->tm_mday);
	if ((current_date >= time_var->tm_mday
		&& current_months - ((time_var->tm_mon + 1) + (time_var->tm_year * 12))
		>= 6) || (lbuff.st_mtime - 3600) > current_time_time_t)
		ft_printf("  %d", time_var->tm_year + 1900);
	else if ((current_date < time_var->tm_mday && current_months
		- ((time_var->tm_mon + 1) + (time_var->tm_year * 12)) - 1 >= 6)
		|| (lbuff.st_mtime - 3600) > current_time_time_t)
		ft_printf("  %d", time_var->tm_year + 1900);
	else
		ft_printf(" %0.2d:%0.2d", time_var->tm_hour, time_var->tm_min);
	free(current_time);
	free(time_var);
}

void	list_thrid(struct stat lbuff, char *all_path)
{
	char	str[256];
	int		how_much;

	if ((S_ISLNK(lbuff.st_mode)))
	{
		how_much = readlink(all_path, str, 256);
		str[how_much] = '\0';
		ft_printf(" -> %s", str);
	}
}

int		list_option(char *path, t_dir **list_1, int tab_options[NBR])
{
	struct stat		lbuff;
	t_dir			*list_1_bck;
	char			*all_path;
	t_biggest_var	var;

	list_1_bck = *list_1;
	biggests_var(&var, path, list_1);
	disp_total(list_1_bck, path, tab_options);
	while (*list_1 != NULL)
	{
		if (!(all_path = add_path(path, (*list_1)->name)))
			return (EXIT_FAILURE);
		lstat(all_path, &lbuff);
		list_first(all_path, var, lbuff);
		list_second(lbuff);
		ft_printf(" %s", (*list_1)->name);
		list_thrid(lbuff, all_path);
		*list_1 = (*list_1)->next;
		if (*list_1 != NULL)
			ft_printf("\n");
		free(all_path);
	}
	ft_printf("\n");
	return (EXIT_SUCCESS);
}

int		list_option_file(char *name)
{
	struct stat		lbuff;
	struct passwd	*uid;
	struct group	*gid;
	int				speright_flag;

	lstat(name, &lbuff);
	speright_flag = permission_master(lbuff, name);
	if (speright_flag == 0)
		ft_printf(" %2hu", lbuff.st_nlink);
	else
		ft_printf(" %1hu", lbuff.st_nlink);
	if ((uid = getpwuid(lbuff.st_uid)) != 0)
		ft_printf(" %s", uid->pw_name);
	if ((gid = getgrgid(lbuff.st_gid)) != 0)
		ft_printf("  %s", gid->gr_name);
	if ((S_ISCHR(lbuff.st_mode)) || ((S_ISBLK(lbuff.st_mode))))
		ft_printf(" %4d, %3d", major(lbuff.st_rdev), minor(lbuff.st_rdev));
	else
		ft_printf("  %lld", lbuff.st_size);
	list_second(lbuff);
	ft_printf(" %s", name);
	list_thrid(lbuff, name);
	return (EXIT_SUCCESS);
}
