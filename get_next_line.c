/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:22:53 by akahir            #+#    #+#             */
/*   Updated: 2024/12/19 14:29:36 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void leaksDetector()
// {
//    system("leaks a.out");
// }

static char *continue_rd(char *str, int fd)
{
    char    buff[BUFFER_SIZE + 1];
    int     rd;
    char    *temp;
    
    rd = 1;
    while (rd > 0)
    {
        rd = read(fd, buff, BUFFER_SIZE);
        if (rd == -1)
        {
            free(str);
            return( NULL);
        }
        buff[rd] = '\0';
        if (!str)
            str = ft_strdup(buff);
        else
        {
            temp = ft_strjoin(str, buff);
            free(str);
            str = temp;
        }
        if (ft_strchr(str, '\n'))
            break;
    }
    return (str);
}

void ft_free(char **str)
{
    free(*str);
    *str = NULL;
}

char	*get_next_line(int fd)
{
    static char *str;
    char        *line;
    char        *newline_pos;
    char        *temp;
    char        *temp_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    str = continue_rd(str, fd);
    if (str == NULL|| *str == '\0')
    {
        ft_free(&str);
        return (NULL);
    }
    newline_pos = ft_strchr(str, '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';
        line = ft_strdup(str);
        temp = ft_strdup(newline_pos + 1);
        free(str);
        str = temp;
        temp_line = ft_strjoin(line, "\n");
        free(line);
        line = temp_line;
    }
    else
    {
        line = ft_strdup(str);
        ft_free(&str);
    }
    return (line);
}
// int main()
// {
//     int fd = open("file.txt", O_RDONLY);
    
//     // atexit(leaksDetector);
//     char *str1;
//     while ((str1 = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", str1);
//         free(str1);
//     }
// }