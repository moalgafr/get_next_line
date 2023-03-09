/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:15:16 by moalgafr          #+#    #+#             */
/*   Updated: 2023/03/03 14:49:45 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update(char *result)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	j = 0;
	if (!result)
	{
		free(result);
		return (NULL);
	}
	while (result[i] != '\0' && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		i++;
	remaining = ft_calloc(ft_strlen(result + i) + 1, sizeof(char));
	if (!remaining)
		return (NULL);
	while (result[i] != '\0')
	{
		remaining[j++] = result[i++];
	}
	remaining[j] = '\0';
	free(result);
	return (remaining);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	k;

	i = 0;
	k = (char)c;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == k)
			return ((char *)&str[i]);
		i++;
	}
	if (k == '\0')
		return ((char *)&str[i]);
	return (0);
}

char	*find_line(char *result)
{
	char	*line;
	int		i;

	i = 0;
	if (!result)
		return (NULL);
	while (result[i] != '\0' && result[i] != '\n')
	{
		i++;
	}
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (result[i] != '\0' && result[i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	if (result[i] && result[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		read_bytes;

	read_bytes = 1;
	buff = ft_calloc(((size_t)BUFFER_SIZE) + 1, sizeof(char));
	if (!buff)
		return (NULL);
	while (read_bytes != 0 && !(ft_strchr(buff, '\n')))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		str = strjoinandfree(str, buff);
	}
	free(buff);
	if (str[0] == '\0')
		return (ft_free(&str));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	if (*str[fd] == '\0')
	{
		free (str[fd]);
		return (NULL);
	}
	line = find_line(str[fd]);
	str[fd] = ft_update(str[fd]);
	return (line);
}

/// int main()
// {
// 	int fd1;
// 	int fd2;
// 	char *str;	
// 	int	i = 0;
// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file1.txt", O_RDONLY);
// 	// if(!(fd1))
// 	while (1)
// 	{
// 			str = get_next_line(fd1);
// 			if (str == NULL)
// 				break ;
// 			printf("fd1= %s", str);
// 			free(str);
// 			str = get_next_line(fd2);
// 			if (str == NULL)
// 				break;
// 			printf(" fd2 = %s", str);
// 			free(str);	
// 	}
// 	free(str);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }