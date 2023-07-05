/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:00:35 by zrock             #+#    #+#             */
/*   Updated: 2023/04/18 20:00:35 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// stores characters from buf into line until first /n, returns its index.
// If no /n, returns 0.

size_t	ft_store(void *buf, char *line, size_t buf_size, size_t j, size_t *i)
{
	char	*buf_c;

	buf_c = (char *)buf;
	while (j < buf_size)
	{
		line[(*i++)] = buf_c[j];
		if (buf_c[j] == '\n')
		{
			if (j == buf_size -1)
				return (0);
			return (j + 1);
		}
		j ++;
	}
	return (0);
}

// reallocates memory for line to +1 buf_size, returns 0 if malloc fails.

int	ft_add_to_line(char *line, size_t buf_size, size_t count)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(buf_size * count * 10);
	if (!temp)
		return (0);
	while (i < buf_size * count * 10)
	{
		temp[i] = line[i];
		i ++;
	}
	free(line);
	line = (char *)malloc(buf_size * (count + 1) * 10);
	if (!line)
		return (0);
	i = 0;
	while (i < buf_size * count * 10)
	{
		temp[i] = line[i];
		i ++;
	}
	free(temp);
	return (1);
}

// makes and returns a line.

char	*make_line(ssize_t *j, size_t buf_size, void *buf, int fd)
{
	char			*line;
	static size_t	end = 1;
	size_t			i;
	char			*cp;
	size_t			count;

	i = 0;
	count = 1;
	cp = (char *)buf;
	line = (char *)malloc(buf_size * 10);
	if (!line || !end)
		return (NULL);
	if (*j)
	{
		*j = ft_store(buf, line, end, *j, &i);
		if (*j)
			return (line);
	}
	while (!*j)
	{
		end = read(fd, buf, buf_size);
		if (count++ % 10 == 0)
			if (!ft_add_to_line(line, buf_size, count))
				return (NULL);
		*j = ft_store(buf, line, end, *j, &i);
	}
	return (line);
}

// int	main(void)
// {
// 	void	*buf;
// 	char	*line;
// 	char	*test = "hello world";

// 	buf = (void *)test;
// 	line = (char *)malloc(12);
// 	if (!line)
// 		return (0);
// 	ft_store(buf, line, 11);
// 	write(1, line, 12);
// 	return (0);
// }
