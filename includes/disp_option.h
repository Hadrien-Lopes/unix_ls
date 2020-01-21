/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_option.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:18:02 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:18:05 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISP_OPTION_H
# define DISP_OPTION_H

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
# include "../includes/useful.h"

char	*disp_mon(int mon);
int		permission_master(struct stat lbuff, char *all_path);
int		disp_total(t_dir *list_1_bck, char *path, int tab_options[NBR]);
#endif
