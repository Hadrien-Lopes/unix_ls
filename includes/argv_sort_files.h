/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sort_files.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:17:35 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:17:38 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_SORT_FILES_H
# define ARGV_SORT_FILES_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/argv_sort_useful.h"

t_sorted_files			*sort_files_master(t_sorted_dir *dir, int tab[NBR]);

#endif
