/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_size.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:19:11 by hmoulher          #+#    #+#             */
/*   Updated: 2019/05/31 13:19:31 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_SIZE_H
# define VAR_SIZE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/libft.h"
# include "../includes/useful.h"

typedef struct	s_biggest_var
{
	int	inode;
	int	file;
	int	uid;
	int	gid;
}				t_biggest_var;

int				biggests_var(t_biggest_var *var, char *path, t_dir **list_1);

#endif
