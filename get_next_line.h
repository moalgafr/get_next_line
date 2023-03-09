/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:04:55 by moalgafr          #+#    #+#             */
/*   Updated: 2023/03/02 00:51:37 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*strjoinandfree(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *dest, int c, size_t len);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	*ft_free(char **str);

#endif