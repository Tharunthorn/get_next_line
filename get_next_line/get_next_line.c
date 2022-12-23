/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmusik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:58:09 by thmusik           #+#    #+#             */
/*   Updated: 2022/12/23 11:05:06 by thmusik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
#include "get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <string.h>


char	*get_next_line(int fd)
{
	unsigned int	linecount;
	char	*string;

	linecount = 0;
	//Buffer Memory Allocation Section
	if (fd < 0)
	{
		//printf("File Descriptor Error\n");
		return (NULL);
	}
	if (buffer == NULL)
	{
		buffer = (char*)calloc(sizeof(char), 1024 + 1);// Memory Leak?, Need Calloc?
		if (!buffer)
		{
			free(buffer);
			//printf("Buffer Memory Allocation Error\n");
			return (NULL);
		}
		read(fd, buffer, 1024 + 1);
	}
	if (buffer[0] != '\0' && buffer[0] != '\n')
	{
		//Line Lenght Section
		while (buffer[linecount] != '\n' && buffer[linecount] != '\0')
			linecount++;
		//Returned String Memory Allocation Section
		string = (char*)calloc(sizeof(char), linecount + 2);
		linecount = 0;
		//Buffer To String Section
		while (buffer[linecount] != '\0')
		{
			if (buffer[linecount] == '\n')
			{
				string[linecount] = buffer[linecount];
				linecount++;
				break ;
			}
			string[linecount] = buffer[linecount];
			linecount++;
		}
		if (buffer[linecount] == '\0')
			string[linecount] = '\0';
		//Buffer Move Section
		buffer += linecount;// Memory Leak?, Secmentation Fault?, Need Temp?
	}
	else if (buffer[0] == '\n')
	{
		buffer += 1;
		string = (char*)calloc(sizeof(char), 2);
		string[0] = '\n';
	}
	else
	{
		//printf("Buffer Empty\n");
		string = NULL;
	}
	return (string);
}

// int main(void)
// {
// 	int		fd;
// 	int		lineplacement;
// 	char	*string;

// 	fd = open("test.txt", O_RDONLY);
// 	lineplacement = 1;
// 	string = get_next_line(fd);
// 	printf("fd: %i\n", fd);
// 	printf("line%i: %s\n", lineplacement, string);
// 	free(string);
// 	return (0);
// }
