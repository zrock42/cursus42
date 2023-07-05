/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:19:10 by zrock             #+#    #+#             */
/*   Updated: 2023/04/18 20:19:10 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static void	static_buf(ssize_t *j, size_t *buf_size, void **buf, int *def)
// {
// 	*buf = malloc(sizeof(char) * *buf_size);
// 	*def = 1;
// }

// char	*get_next_line(int fd)
// {
// 	static size_t	j = 0;
// 	static size_t	buf_size = 10;
// 	static void		*buf;
// 	static int		def = 0;

// 	if (!def)
// 		static_buf(&j, &buf_size, &buf, &def);
// 	if (!buf)
// 		return (NULL);
// 	return (make_line(buf, &j, buf_size, fd));
// }

int	main(void)
{
	int			fd;
	FILE		*fp;
	void		*buf;
	ssize_t		x;

	x = 0;
	buf = malloc(15);
	fp = fopen("test_get", "r");
	fd = fileno(fp);
	printf("%i", (int)ft_read(fd, buf, 15, &x));
	write(1, (char *)buf, 15);
}
