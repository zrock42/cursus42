#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

char	*get_next_line(int fd);
ssize_t	ft_read(int fd, void *buf, size_t buf_size);
size_t	ft_store(void *buf, char *line, size_t n);
int		ft_buf(char *buf, ssize_t *j, size_t buf_size, char *line, size_t *i);
char	*make_line(void *buf, char *line, ssize_t *j, size_t buf_size, size_t *i);

#endif