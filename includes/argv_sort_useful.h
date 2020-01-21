/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sort_useful.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:17:49 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:17:50 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_SORT_USEFUL_H
# define ARGV_SORT_USEFUL_H

# include "../includes/sort.h"
# include "../includes/useful.h"

void	swap_files(t_sorted_dir *dir, int *proceed);
void	swap_folder(t_sorted_dir *dir, int *proceed);
int		norme(t_dir *list_bck);
int		pls(t_dir *list, int tab[NBR], t_dir *list_bck, t_sorted_dir *s_dir);
void	check_all_files(char const *argv[], int i);

#endif
