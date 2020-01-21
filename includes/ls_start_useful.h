/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_start_useful.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:18:31 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:18:33 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_START_USEFUL_H
# define LS_START_USEFUL_H

# include <stdlib.h>
# include "../includes/sort.h"
# include "../includes/useful.h"
# include "../includes/option.h"
# include "../libft/libft.h"

int		init_tab(int tab_options[NBR], int argc, char const *argv[]);
void	init_dir(t_sorted_dir *sd, int tab_options[NBR]);
void	init_dir_argv(t_sorted_dir *sd, int pos, const char *v[], int tab[NBR]);

#endif
