/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:17:17 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:10:19 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "get_next_line_bonus.h"

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*read_first_line_bonus(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free(buffer);
	return (text);
}

char	*get_line_bonus(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text || !text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = ft_calloc((size_t)i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*clean_first_line_bonus(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(text) - (size_t)i + 1, sizeof(char));
	if (!str)
	{
		free(text);
		return (NULL);
	}
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free(text);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text[4096];

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(text[fd]);
		text[fd] = NULL;
		return (NULL);
	}
	text[fd] = read_first_line_bonus(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = get_line_bonus(text[fd]);
	if (!line)
	{
		free(text[fd]);
		text[fd] = NULL;
		return (NULL);
	}
	text[fd] = clean_first_line_bonus(text[fd]);
	return (line);
}
/*#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	p(char *label, char *line)
{
	if (line)
	{
		write(1, label, 4);
		write(1, ": ", 2);
		write(1, line, ft_strlen(line));
		free(line);
	}
	else
	{
		write(1, label, 4);
		write(1, ": NULL\n", 7);
	}
}

int	main(void)
{
	int	fd1 = open("a.txt", O_RDONLY);
	int	fd2 = open("b.txt", O_RDONLY);

	p("fd1", get_next_line(fd1)); // A1\n
	p("fd2", get_next_line(fd2)); // B1\n
	p("fd1", get_next_line(fd1)); // A2\n
	p("fd2", get_next_line(fd2)); // B2\n
	p("fd1", get_next_line(fd1)); // A3\n
	p("fd2", get_next_line(fd2)); // B3\n
	p("fd1", get_next_line(fd1)); // NULL
	p("fd2", get_next_line(fd2)); // NULL

	close(fd1);
	close(fd2);
}*/
