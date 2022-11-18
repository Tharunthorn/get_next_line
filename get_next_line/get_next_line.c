/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmusik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:58:09 by thmusik           #+#    #+#             */
/*   Updated: 2022/11/18 16:00:25 by thmusik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <fcntl.h>
# include <string.h>

static char	*str1;

char	*get_next_line(int fd)
{
	int 	line;
	unsigned long	i;
	char	*str2;
	char	*buff;

	buff = (char*)calloc(sizeof(char), 1024);
	if (fd == -1 && buff == NULL)
		return NULL;
	if (str1 == NULL)
		str1 = (char*)calloc(sizeof(char), 1024);
	str2 = (char*)calloc(sizeof(char), strlen(str1));
	line = read(fd, buff, 1);
	while (line > 0)
	{
		str1 = strcat(str1, buff);
		free(buff);
		buff = (char*)calloc(sizeof(char), 1024);
		line = read(fd, buff, 1);
	}
	free(buff);
	i = 0;
	while (i <= strlen(str1))
	{
		str2[i] = str1[i];
		if (str1[i] == '\n')
			break;
		i++;
	}
	i++;
	str1 += i;
	if(str1)
		return (str2);
	return (NULL);
}

