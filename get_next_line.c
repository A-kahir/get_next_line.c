/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:22:53 by akahir            #+#    #+#             */
/*   Updated: 2024/12/18 20:14:12 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void leaksDetector()
// {
//    system("leaks a.out");
// }

static	char	*func_read(int fd)
{
    char	*Buff;
    int		read_byt;
    
    Buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (Buff == NULL)
        return (NULL);
    read_byt = read(fd, Buff, BUFFER_SIZE);
    if (read_byt <= 0)
    {
        free(Buff);
        return (NULL);
    }
    Buff[read_byt] = '\0';
    return (Buff);
}

static char *continue_rd(char *str, int fd)
{
    char    buff[BUFFER_SIZE + 1];
    int     rd;
    char    *temp;

    if (!str)
        str = func_read(fd);
    while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[rd] = '\0';
        temp = ft_strjoin(str, buff);
        free(str);
        str = temp;
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

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = continue_rd(str, fd);
    if (str == NULL || *str == '\0')
        return (NULL);
    newline_pos = ft_strchr(str, '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';
        printf("\n newline_pos==> %s\n", newline_pos);
        line = ft_strdup(str);
        temp = ft_strdup(newline_pos + 1);
        free(str);
        str = temp;
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
        printf("%s\n", str1);
        free(str1);
    }
}
