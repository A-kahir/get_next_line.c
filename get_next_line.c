/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:22:53 by akahir            #+#    #+#             */
/*   Updated: 2024/12/19 18:30:36 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void leaksDetector()
// {
//    system("leaks a.out");
// }

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
            temp = ft_strdup(buff);
        else
        {
            temp = ft_strjoin(str, buff);
            if(temp == NULL)
                return (free(buff), free(str), NULL);
        }
        free(str);
        str = temp;
        if (ft_strchr(str, '\n'))
            break;
    }
    free(buff);
    return (str);
}

char	*get_next_line(int fd)
{
    static char *str;
    char        *line;
    char        *newline_pos;
    char        *temp;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (ft_free(&str), NULL);
    str = continue_rd(str, fd);
    if (str == NULL|| *str == '\0')
        return (ft_free(&str), NULL);
    newline_pos = ft_strchr(str, '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';
        line = ft_strdup(str);
        temp = ft_strdup(newline_pos + 1);
		if (line == NULL || temp == NULL)
			return (ft_free(&str), free(line), free(temp),NULL);
        free(str);
        str = temp;
        temp = ft_strjoin(line, "\n");
        free(line);
		if (temp == NULL)
			return (ft_free(&str), NULL);
        line = temp;
    }
    else
    {
        line = ft_strdup(str);
        ft_free(&str);
    }
    return (line);
}
int main()
{
    int fd = open("file.txt", O_RDONLY);
    
    // atexit(leaksDetector);
    char *str1;
    while ((str1 = get_next_line(fd)) != NULL)
    {
        printf("%s", str1);
        free(str1);
    }
}