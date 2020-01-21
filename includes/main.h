/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:01:34 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/10 14:02:03 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include "../libft/libft.h"
# include "../includes/list_option.h"
# include "../includes/useful.h"
# include "../includes/sort.h"
# include "../includes/option.h"
# include "../includes/ls_display_useful.h"
# include "../includes/ls_start_useful.h"
# include "../includes/sort_files.h"
# include "../includes/recursive_option.h"

t_dir	*sort_master(t_dir *list, int tab_options[NBR], char *path, int *flag);
int		recursive_control(t_sorted_dir *sd, int tab_options[NBR]);
int		ls_display(t_sorted_dir *sd, int tab_options[NBR]);
void	ls_start(int argc, char const *argv[]);
#endif
