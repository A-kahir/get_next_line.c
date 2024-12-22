/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:12:25 by akahir            #+#    #+#             */
/*   Updated: 2024/12/22 14:51:35 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libc.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif