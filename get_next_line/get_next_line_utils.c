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

size_t	ft_store(void *buf, char *line, size_t buf_size, size_t j)
{
	char	*buf_c;
	size_t	i;

	i = 0;
	buf_c = (char *)buf;
	while (j < buf_size)
	{
		line[i] = buf_c[j];
		if (buf_c[j] == '\n')
		{
			if (j == buf_size -1)
				return (0);
			return (j + 1);
		}
		i ++;
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
	temp = (char *)malloc(buf_size * count);
	if (!temp)
		return (0);
	while (i < buf_size * count)
	{
		temp[i] = line[i];
		i ++;
	}
	free(line);
	line = (char *)malloc(buf_size * (count + 1));
	if (!line)
		return (0);
	i = 0;
	while (i < buf_size * count)
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
	char	*line;
	int		end;
	size_t	i;
	char	*cp;
	size_t	count;

	i = 0;
	end = 0;
	count = 1;
	cp = (char *)buf;
	line = (char *)malloc(buf_size * 10);
	if (!line)
		return (NULL);
	if (*j)
		if (ft_store(buf, line, buf_size, *j))
			return (line);
	if (read(fd, buf, buf_size) < buf_size)
		end = 1;
	while (!*j)
	{
		if (count % 10 == 0)
			if (!ft_add_to_line(line, buf_size))
				return (NULL);
	}
}
// {
// 	char	*line;
// 	char	*temp;
// 	size_t	count;
// 	size_t	i;
// 	ssize_t	bytes_read;

// 	bytes_read = 0;
// 	line = (char *)malloc(buf_size);
// 	if (!line)
// 		return (NULL);
// 	count = 0;
// 	i = 0;
// 	if (*j > -1)
// 		i += ft_buf((char *)buf, j, buf_size, line);
// 	while (*j == -1)
// 	{
// 		*j = ft_read(fd, buf, buf_size, &bytes_read);
// 		count ++;
// 		if (!ft_add_to_line(line, temp, buf_size, count))
// 			return (NULL);
// 		if (j != -1)
// 		{
// 			ft_store(buf, line[buf_size * count], *j + 1);
// 			return (line);
// 		}
// 		ft_store(buf, line[buf_size * count], buf_size);
// 	}


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
