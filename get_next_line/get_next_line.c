#include <unistd.h>

void	static_vars(ssize_t *j, size_t *buf_size, void **buf, int *def)
{
	*j = -1;
	*buf_size = 10;
	*buf = malloc(sizeof(char) * buf_size);
	*def = 1;
}

char *get_next_line(int fd)
{
	size_t			i;
	char			line[100000001];
	static ssize_t	j;
	static size_t	buf_size;
	static void		*buf;
	static int		def;

	if (!def)
		static_vars(&j, &buf_size, &buf, &def)
	if (!buf)
		return (NULL);
	i = 0;
	if (j > -1)
		if (ft_buf((char *)buf, j, buf_size, line, &i))
			return (line);
	if (/*end of file*/)
		free(buf);
	return (make_line(buf, line, &j, buf_size, &i));
	return line;
}
