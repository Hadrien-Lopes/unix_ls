/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_option.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:00:33 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:18:13 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_OPTION_H
# define LIST_OPTION_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include "../libft/libft.h"
# include "../includes/main.h"
# include "../includes/useful.h"
# include "../includes/var_size.h"
# include "../includes/disp_option.h"

char			*disp_mon(int mon);
int				biggest_inode(char *path, t_dir *list);
int				biggest_uid(char *path, t_dir *list);
int				biggest_gid(char *path, t_dir *list);
int				biggest_file(char *path, t_dir *list);
int				list_option(char *path, t_dir **list_1, int tab_options[NBR]);
int				list_option_file(char *name);

#endif
