/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:12:09 by akahir            #+#    #+#             */
/*   Updated: 2024/12/20 13:34:52 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void ft_free(char **str)
{
    if (*str)
    {
        free(*str);
        *str = NULL;
    }
}

static char *continue_rd(char *str, int fd)
{
    char    *buff;
    int     rd;
    char    *temp;
    
    buff = malloc((size_t)BUFFER_SIZE + 1);
    if (buff == NULL)
        return(ft_free(&str), NULL);
    rd = 1;
    while (rd > 0)
    {
        rd = read(fd, buff, BUFFER_SIZE);
        if (rd == -1)
            return (free(buff), ft_free(&str), NULL);
        if (rd == 0)
            break;
        buff[rd] = '\0';
        if (!str)
		{
            temp = ft_strdup(buff);
		}
        else
        {
            temp = ft_strjoin(str, buff);
            if(temp == NULL)
                return (free(buff), free(str), NULL);
        	free(str);
        }
        str = temp;
        if (ft_strchr(str, '\n'))
            break;
    }
    free(buff);
    return (str);
}

char	*get_next_line(int fd)
{
    static char *str[OPEN_MAX];
    char        *line;
    char        *newline_pos;
    char        *temp;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (ft_free(&str[fd]), NULL);
    str[fd] = continue_rd(str[fd], fd);
    if (str[fd] == NULL|| *str[fd] == '\0')
        return (ft_free(&str[fd]), NULL);
    newline_pos = ft_strchr(str[fd], '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';
        line = ft_strdup(str[fd]);
        temp = ft_strdup(newline_pos + 1);
		if (line == NULL || temp == NULL)
			return (ft_free(&str[fd]), free(line), free(temp),NULL);
        free(str[fd]);
        str[fd] = temp;
        temp = ft_strjoin(line, "\n");
        free(line);
		if (temp == NULL)
			return (ft_free(&str[fd]), NULL);
        line = temp;
    }
    else
    {
        line = ft_strdup(str[fd]);
        ft_free(&str[fd]);
    }
    return (line);
}