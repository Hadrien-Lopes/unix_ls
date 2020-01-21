/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_useful.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:18:25 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:18:26 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_DISPLAY_USEFUL_H
# define LS_DISPLAY_USEFUL_H

# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include "../includes/useful.h"
# include "../includes/list_option.h"
# include "../includes/main.h"

void	ls_disp_files(t_sorted_dir *sorted_dir, int tab_options[NBR]);
int		ulti_test(DIR *dir_1, int tab_options[NBR],
	t_sorted_dir *sorted_dir, t_dir *list_1);

#endif
