/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmusik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:07:32 by thmusik           #+#    #+#             */
/*   Updated: 2023/01/15 13:16:29 by thmusik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next(char *string)
{
	char	*next;
	int		index1;
	int		index2;

	index1 = 0;
	while (*(string + index1) && *(string + index1) != '\n')
		index1++;
	if (!*(string + index1))
	{
		free(string);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(string) - index1 + 1));
	if (!next)
		return (NULL);
	index1++;
	index2 = 0;
	while (*(string + index1))
		*(next + index2++) = *(string + index1++);
	*(next + index2) = '\0';
	free(string);
	return (next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		string = get_string(fd, string);
		if (!string)
			return (NULL);
		line = get_line(string);
		string = get_next(string);
		return (line);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("test", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("get: %s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("get: %s", str);
// 	return (0);
// }
