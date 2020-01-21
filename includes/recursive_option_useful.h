/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_option_useful.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:10:13 by hmoulher          #+#    #+#             */
/*   Updated: 2019/08/16 13:10:17 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSIVE_OPTION_USEFUL_H
# define RECURSIVE_OPTION_USEFUL_H

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include "../includes/useful.h"
# include "../libft/libft.h"

void	add_path_2(char *path, char *name, char all_path[2048]);
int		check_file_for_recursive(char *na, t_dir *lb, t_dir *l, char ap[2048]);

#endif
