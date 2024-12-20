/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:22:53 by akahir            #+#    #+#             */
/*   Updated: 2024/12/20 17:26:19 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_operation1(char *str, char *temp, char *buff)
{
	if (!str)
		temp = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(str, buff);
		if (temp == NULL)
			return (free(buff), free(str), NULL);
		free(str);
	}
	return (temp);
}

static	char	*continue_rd(char *str, int fd)
{
	char	*buff;
	int		rd;
	char	*temp;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (buff == NULL)
		return (free(str), str = NULL, NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (free(buff), free(str), str = NULL, NULL);
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		temp = ft_operation1(str, temp, buff);
		str = temp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*newline_pos;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str), str = NULL, NULL);
	str = continue_rd(str, fd);
	if (str == NULL || *str == '\0')
		return (free(str), str = NULL, NULL);
	newline_pos = ft_strchr(str, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(str);
		temp = ft_strdup(newline_pos + 1);
		if (line == NULL || temp == NULL)
			return (free(str), str = NULL, free(line), free(temp), NULL);
		free(str);
		str = temp;
		temp = ft_strjoin(line, "\n");
		free(line);
		if (temp == NULL)
			return (free(str), str = NULL, NULL);
		line = temp;
	}
	else
	{
		line = ft_strdup(str);
		free(str);
		str = NULL;
	}
	return (line);
}
