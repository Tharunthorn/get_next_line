/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmusik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:51:50 by thmusik           #+#    #+#             */
/*   Updated: 2023/01/09 10:02:17 by thmusik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

static char *string;

char *ft_strjoin(char *s, char *buff);

char *ft_strchr(char *s, int c);

size_t ft_strlen(char *s);

char *get_string(int fd);

char *get_line(void);

char *get_next(void);

char	*get_next_line(int fd);

#endif
