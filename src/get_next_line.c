/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:27:16 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/25 23:27:17 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*my_strjoin(char *buffer, char *str)
{
	char	*tmp;

	if (!buffer || !str)
		return (NULL);
	tmp = buffer;
	buffer = ft_strjoin(buffer, str);
	free(tmp);
	return (buffer);
}

char	*get_line(char **buff)
{
	char	*line;
	char	*new;
	char	*pos;

	if (ft_strchr(*buff, '\n'))
	{
		pos = ft_strchr(*buff, '\n');
		line = ft_substr(*buff, 0, pos - *buff + 1);
		new = ft_strdup(pos + 1);
		free(*buff);
		*buff = new;
		return (line);
	}
	else
	{
		line = ft_strdup(*buff);
		free(*buff);
		*buff = NULL;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	char		tmp[10];
	int			br;
	static char	*buff;

	br = 0;
	if (!buff)
		buff = ft_strdup("");
	while (1)
	{
		br = read(fd, tmp, 9);
		if (br <= 0)
			break ;
		tmp[br] = '\0';
		buff = my_strjoin(buff, tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (*buff != '\0')
		return (get_line(&buff));
	else
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
}
