//#include "get_next_line.h"
#include <unistd.h>
// fills buf with buf_size characters from fd, returns the index of first \n or -1 if none are found

ssize_t	ft_read(int fd, void *buf, size_t buf_size)
{
	size_t	i;
	ssize_t	j;
	char	*cp;
	
	j = read(fd, buf, buf_size);
	cp = (char *)buf;
	i = 0;
	while(i < buf_size)
		if (cp[i++] == \n)
			return (i - 1);
	return (-1);
}

// stores n characters from buf into line, returns n

size_t	ft_store(void *buf, char *line, size_t n)
{
	char	*cp;
	size_t	i;

	cp = (char *)buf;
	i = 0;
	while (n--)
		line[i] = cp[i++];
	return (n);
}

// handles a buffer with one or more \n characters, starting at index j. Returns 1 if there is another \n, 0 othherwise.

int	ft_buf(char *buf, ssize_t *j, size_t buf_size, char *line, size_t *i)
{
	while(buf[*j] != '\n' && *j < buf_size)
		line[*i++] = buf[*j++];
	if (*j == buf_size)
	{
		*j = -1;
		return (0);
	}
	return (1);
}

// makes a line starting with an empty buffer and at line[i].

char	*make_line(void *buf, char *line, ssize_t *j, size_t buf_size, size_t *i)
{
	while (1)
	{
		j = ft_read(fd, buf, buf_size);
		if (*j != -1)
		{
			*i += ft_store(buf, &line[*i], *j + 1);
			line[*i] = '\0';
			*j++;
			return (line);
		}
		*i += ft_store(buf, line[*i], buf_size);
	}
}

int	main(void)
{
	void	*buf;
	char	*line;
	char	*test = "hello world";

	buf = (void *)test;
	ft_store(buf, line, 5);
	write(1, line, 12);
	return (0);
}