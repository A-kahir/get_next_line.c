/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:12:09 by akahir            #+#    #+#             */
/*   Updated: 2024/12/22 20:39:31 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_operation(char *str, char *temp, char *buff)
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

static	char	*continue_rd(char *str, int fd, char *buff)
{
	int		rd;
	char	*temp;

	temp = NULL;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (free(buff), free(str), NULL);
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		temp = ft_operation(str, temp, buff);
		if (temp == NULL)
			return (free(buff), NULL);
		str = temp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

static char	*return_and_save(char *newline_pos, char **str, char **line)
{
	char	*temp;

	if (newline_pos)
	{
		*newline_pos = '\0';
		*line = ft_strdup(*str);
		temp = ft_strdup(newline_pos + 1);
		if (!(*line) || !temp)
			return (free(*str), *str = NULL, free(*line), free(temp), NULL);
		free(*str);
		*str = temp;
		temp = ft_strjoin(*line, "\n");
		if (temp == NULL)
			return (free(*str), *str = NULL, free(*line), NULL);
		free(*line);
		*line = temp;
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;
	char		*newline_pos;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str[fd]), str[fd] = NULL, NULL);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (buff == NULL)
		return (free(str), NULL);
	str[fd] = continue_rd(str[fd], fd, buff);
	if (!str[fd] || *str[fd] == '\0')
		return (free(str[fd]), str[fd] = NULL, NULL);
	newline_pos = ft_strchr(str[fd], '\n');
	return (return_and_save(newline_pos, &str[fd], &line));
}
