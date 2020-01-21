/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:11:53 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:11:55 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/disp_option.h"

char		*disp_mon(int mon)
{
	if (mon == 0)
		return ("Jan");
	else if (mon == 1)
		return ("Feb");
	else if (mon == 2)
		return ("Mar");
	else if (mon == 3)
		return ("Apr");
	else if (mon == 4)
		return ("May");
	else if (mon == 5)
		return ("Jun");
	else if (mon == 6)
		return ("Jul");
	else if (mon == 7)
		return ("Aug");
	else if (mon == 8)
		return ("Sep");
	else if (mon == 9)
		return ("Oct");
	else if (mon == 10)
		return ("Nov");
	else if (mon == 11)
		return ("Dec");
	return (NULL);
}

static void	permission_first(struct stat lbuff)
{
	if ((S_ISREG(lbuff.st_mode)))
		ft_printf("-");
	else if ((S_ISDIR(lbuff.st_mode)))
		ft_printf("d");
	else if ((S_ISCHR(lbuff.st_mode)))
		ft_printf("c");
	else if ((S_ISBLK(lbuff.st_mode)))
		ft_printf("b");
	else if ((S_ISFIFO(lbuff.st_mode)))
		ft_printf("p");
	else if ((S_ISLNK(lbuff.st_mode)))
		ft_printf("l");
	else if ((S_ISSOCK(lbuff.st_mode)))
		ft_printf("s");
	ft_printf((lbuff.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((lbuff.st_mode & S_IWUSR) ? "w" : "-");
	if ((lbuff.st_mode & S_ISUID))
	{
		if ((lbuff.st_mode & S_IXUSR))
			ft_printf("s");
		else
			ft_printf("S");
	}
	else
		ft_printf((lbuff.st_mode & S_IXUSR) ? "x" : "-");
}

static void	permission_second(struct stat lbuff)
{
	ft_printf((lbuff.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((lbuff.st_mode & S_IWGRP) ? "w" : "-");
	if ((lbuff.st_mode & S_ISGID))
	{
		if ((lbuff.st_mode & S_IXGRP))
			ft_printf("s");
		else
			ft_printf("S");
	}
	else
		ft_printf((lbuff.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((lbuff.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((lbuff.st_mode & S_IWOTH) ? "w" : "-");
	if ((lbuff.st_mode & S_ISVTX))
	{
		if ((lbuff.st_mode & S_IXOTH))
			ft_printf("t");
		else
			ft_printf("T");
	}
	else
		ft_printf((lbuff.st_mode & S_IXOTH) ? "x" : "-");
}

int			permission_master(struct stat lbuff, char *all_path)
{
	acl_t	acl;
	ssize_t	xattr;
	int		speright_flag;

	acl = NULL;
	xattr = 0;
	speright_flag = 0;
	permission_first(lbuff);
	permission_second(lbuff);
	acl = acl_get_link_np(all_path, ACL_TYPE_EXTENDED);
	xattr = listxattr(all_path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
	{
		ft_printf("@");
		speright_flag = 1;
	}
	else if (acl != NULL)
	{
		ft_printf("+");
		speright_flag = 1;
	}
	free(acl);
	return (speright_flag);
}

int			disp_total(t_dir *list_1_bck, char *path, int tab_options[NBR])
{
	struct stat	lbuff;
	char		*all_path;
	long		total_size;

	total_size = 0;
	while (list_1_bck != NULL)
	{
		if (!(all_path = add_path(path, list_1_bck->name)))
			return (EXIT_FAILURE);
		if (list_1_bck->name[0] != '.' || tab_options[1] == 1)
		{
			lstat(all_path, &lbuff);
			total_size += lbuff.st_blocks;
		}
		list_1_bck = list_1_bck->next;
		free(all_path);
	}
	ft_printf("total %ld\n", total_size);
	return (EXIT_FAILURE);
}
