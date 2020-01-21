/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:02:44 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:18:57 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../includes/useful.h"
# include "../includes/argv_sort_useful.h"
# include "../includes/argv_sort_files.h"
# include "../includes/argv_sort_folder.h"

t_sorted_dir	*sort_argv(char const *argv[], int file_pos,
	t_sorted_dir *sorted_dir, int tab_option[NBR]);
t_sorted_files	*file(t_sorted_dir *sorted_dir, const char *name);
t_sorted_folder	*folder(t_sorted_dir *sorted_dir, const char *name);
#endif
