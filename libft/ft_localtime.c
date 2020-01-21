/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_localtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:46:12 by hmoulher          #+#    #+#             */
/*   Updated: 2019/08/16 12:46:15 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ret_mon(char *mon)
{
	if (!(ft_strcmp(mon, "Jan")))
		return (0);
	else if (!(ft_strcmp(mon, "Feb")))
		return (1);
	else if (!(ft_strcmp(mon, "Mar")))
		return (2);
	else if (!(ft_strcmp(mon, "Apr")))
		return (3);
	else if (!(ft_strcmp(mon, "May")))
		return (4);
	else if (!(ft_strcmp(mon, "Jun")))
		return (5);
	else if (!(ft_strcmp(mon, "Jul")))
		return (6);
	else if (!(ft_strcmp(mon, "Aug")))
		return (7);
	else if (!(ft_strcmp(mon, "Sep")))
		return (8);
	else if (!(ft_strcmp(mon, "Oct")))
		return (9);
	else if (!(ft_strcmp(mon, "Nov")))
		return (10);
	else if (!(ft_strcmp(mon, "Dec")))
		return (11);
	return (-1);
}

struct	tm	*ft_localtime(time_t *timep)
{
	struct tm	*fake_locatime;
	char		tmp_buffer[256];
	char		tmp2[256];
	char		*t_str;

	fake_locatime = (struct tm*)malloc(sizeof(struct tm));
	t_str = ctime(timep);
	fake_locatime->tm_sec = ft_atoi(ft_strncpy(tmp_buffer, t_str + 17, 2));
	fake_locatime->tm_min = ft_atoi(ft_strncpy(tmp_buffer, t_str + 14, 2));
	fake_locatime->tm_hour = ft_atoi(ft_strncpy(tmp_buffer, t_str + 11, 2));
	fake_locatime->tm_mday = ft_atoi(ft_strncpy(tmp_buffer, t_str + 8, 2));
	fake_locatime->tm_mon = ret_mon(ft_strncpy(tmp_buffer, t_str + 4, 3));
	fake_locatime->tm_year = ft_atoi(ft_strncpy(tmp2, t_str + 20, 15)) - 1900;
	return (fake_locatime);
}
