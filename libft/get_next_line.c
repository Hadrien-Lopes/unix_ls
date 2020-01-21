/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:25:41 by hmoulher          #+#    #+#             */
/*   Updated: 2018/12/04 10:58:59 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	reply_one(char *str, char **residual_buffer, char **line)
{
	*residual_buffer = ft_strdup(*residual_buffer);
	(*residual_buffer)++;
	line[0] = ft_strsub(str, 0,
		ft_strlen(str) - ft_strlen(*residual_buffer) - 1);
	free(str);
	return (1);
}

static int	reply_two(char *str, char **line)
{
	line[0] = ft_strsub(str, 0, ft_strlen(str));
	return (1);
}

static char	*init_str(char *residual_buffer)
{
	if (residual_buffer)
		return (ft_strdup(residual_buffer));
	else
		return (ft_strnew(1));
}

int			get_next_line(const int fd, char **line)
{
	int			read_reply;
	char		*str;
	char		buff[BUFF_SIZE + 1];
	static char *residual_buffer[FOPEN_MAX];

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	str = init_str(residual_buffer[fd]);
	if ((residual_buffer[fd] = ft_strchr(str, '\n')))
		return (reply_one(str, &residual_buffer[fd], line));
	while ((read_reply = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_reply] = '\0';
		str = ft_strjoin_free(str, buff);
		if ((residual_buffer[fd] = ft_strchr(str, '\n')))
			return (reply_one(str, &residual_buffer[fd], line));
		else if (read_reply < BUFF_SIZE)
			return (reply_two(str, line));
	}
	if ((residual_buffer[fd] = ft_strchr(str, '\n')) == NULL && str[0] != '\0')
		return (reply_two(str, line));
	if (read_reply <= 0)
		return (read_reply);
	return (1);
}
