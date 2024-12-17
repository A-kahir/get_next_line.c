/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:23 by akahir            #+#    #+#             */
/*   Updated: 2024/12/16 20:19:24 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == (char)c)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(&s[i]));
	}
	return (NULL);
}

/*

static char *continue_rd(char *str, int fd)
{
    char *stock;
    char *temp;
    char *newline_pos;
    int i;
    int j;

    if (str == NULL)
        return (NULL);
    stock = ft_strdup(str);
    if (stock == NULL)
        return (NULL);
    free(str);
    while (1)
	{
        str = func_read(fd);
        if (str == NULL)
            break;
        temp = stock;
        stock = malloc(ft_strlen(temp) + ft_strlen(str) + 2);
        if (stock == NULL)
		{
            free(temp);
            free(str);
            return (NULL);
        }
		i = 0;
        while (temp[i] != '\0')
		{
            stock[i] = temp[i];
            i++;
        }
        j = 0;
        while (str[j] != '\0')
        {
            stock[i + j] = str[j];
            printf("\n\n stock[%d] == > %s\n", i, stock);
            j++;
        }
		stock[i + j] = '\0';
        free(temp);
        free(str);
        newline_pos = strchr(stock, '\n');
        if (newline_pos != NULL)
        {
            *newline_pos = '\0';
            break;
        }
    }
    return (stock);
}
*/