/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sort_folder.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:17:43 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:17:44 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_SORT_FOLDER_H
# define ARGV_SORT_FOLDER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/argv_sort_useful.h"

t_sorted_folder			*sort_folder_master(t_sorted_dir *dir, int tab[NBR]);

#endif
