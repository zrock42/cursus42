/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:03:57 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:06:58 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct storage
{
	int			a;
	int			b;
	int			c;
	ssize_t		w;
	long long	p;
	size_t		read;
	ssize_t		count;
}				t_storage;

int				ft_atoi(const char *s);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
unsigned int	ft_empty_flag(const char *s, t_storage *store);
void			ft_print_char(int c, t_storage *store);
void			ft_print_str(char *s, t_storage *store);
void			ft_print_void(void *p, t_storage *store);
void			ft_print_int(int nb, t_storage *store);
void			ft_print_uint(int nb, t_storage *store);
void			ft_printuint(int nb, t_storage *store);
void			ft_print_hex(unsigned int nb, t_storage *store, char x);
int				ft_printf(const char *s, ...);

#endif