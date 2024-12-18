/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:09:30 by akahir            #+#    #+#             */
/*   Updated: 2024/12/18 19:31:56 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libc.h>

// Func :
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int     ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strcpy(char *dest, const char *src);
char *ft_strcat(char *dest, const char *src);
# endif