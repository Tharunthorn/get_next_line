/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmusik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:51:48 by thmusik           #+#    #+#             */
/*   Updated: 2023/01/11 16:47:11 by thmusik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return ((char *)&*(s + i));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = *(s + i);
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(s) + ft_strlen(buff)] = '\0';
	free(s);
	return (str);
}

char	*get_string(int fd, char *string)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(string, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free(buffer);
	return (string);
}

char	*get_line(char *string)
{
	char	*line;
	int		index;

	index = 0;
	if (!*(string + index))
		return (NULL);
	while (*(string + index) && *(string + index) != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = 0;
	while (*(string + index) && *(string + index) != '\n')
	{
		*(line + index) = *(string + index);
		index++;
	}
	if (*(string + index) == '\n')
	{
		*(line + index) = *(string + index);
		index++;
	}
	*(line + index) = '\0';
	return (line);
}
