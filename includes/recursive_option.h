/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_option.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:18:39 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:18:41 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSIVE_OPTION_H
# define RECURSIVE_OPTION_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include "../includes/recursive_option_useful.h"
# include "../includes/list_option.h"
# include "../includes/useful.h"
# include "../libft/libft.h"

int	recursive(char *name, int tab_options[NBR], int nbr_arg);

#endif
