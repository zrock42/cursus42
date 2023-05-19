/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:20:12 by zrock             #+#    #+#             */
/*   Updated: 2023/05/13 17:20:12 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//char	*get_next_line(int fd);
ssize_t	ft_read(int fd, void *buf, size_t buf_size, ssize_t *bytes_read);
size_t	ft_store(void *buf, char *line, size_t buf_size, size_t j);
char	*make_line(size_t *j, size_t buf_size, void *buf, int fd);

#endif