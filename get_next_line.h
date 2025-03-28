/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:05:02 by edmatevo          #+#    #+#             */
/*   Updated: 2025/03/28 16:35:41 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char    *get_next_line(int fd);
int	    ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);

#endif