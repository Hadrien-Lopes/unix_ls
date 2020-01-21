/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:03:10 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/10 14:09:40 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFUL_H
# define USEFUL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# define NBR 7

typedef struct				s_dir
{
	char					*name;
	struct s_dir			*next;
	struct s_dir			*previous;
}							t_dir;

typedef struct				s_sorted_files
{
	char					*name;
	struct s_sorted_files	*next;
	struct s_sorted_files	*previous;
}							t_sorted_files;

typedef struct				s_sorted_folder
{
	char					*name;
	struct s_sorted_folder	*next;
	struct s_sorted_folder	*previous;
}							t_sorted_folder;

typedef struct				s_sorted_dir
{
	t_sorted_files			*sorted_files;
	t_sorted_folder			*sorted_folder;
}							t_sorted_dir;

void						free_t_dir(t_dir *list);
void						free_sorted_dir(t_sorted_dir *sorted_dir);
t_dir						*add_to_list(t_dir *list, char *d_name);
char						*add_path(char *path, char *name);
int							disp_error(char const *file_name);

#endif
