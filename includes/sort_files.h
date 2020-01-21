/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:19:02 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:19:04 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_FILES_H
# define SORT_FILES_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include "../includes/useful.h"
# include "../libft/libft.h"

t_dir	*sort_rt(t_dir *list, char *path);
t_dir	*sort_t(t_dir *list, char *path);
t_dir	*sort(t_dir *list, int tab_options[NBR]);

#endif
