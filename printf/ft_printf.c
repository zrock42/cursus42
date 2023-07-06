/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:16:54 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:53 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned int	ft_precision(const char *s, t_storage *store)
{
	size_t	i;

	i = 0;
	if (s[i] == '.')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		store->p = ft_atoi(&s[i]);
	else
		store->p = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

static unsigned int	ft_flag_mods(const char *s, t_storage *store)
{
	size_t	i;

	i = 0;
	while (s[i] == '-' || s[i] == '0' || s[i] == '+'
		|| s[i] == '#' || s[i] == ' ')
	{
		if (s[i] == '-')
			store->c = 2;
		if (s[i] == '0' && store->c == 0)
			store->c = 1;
		if (s[i] == '+')
			store->b = 2;
		if (s[i] == ' ' && store->b == 0)
			store->b = 1;
		if (s[i] == '#')
			store->a = 1;
		i++;
	}
	if (s[i] >= '0' && s[i] <= '9')
		store->w = ft_atoi(&s[i]);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

// mods[0]: 1 if '#' 
// mods[1]: 1 if ' ', 2 if '+' 
// mods[2]: 1 if '0', 2 if '-'
// mods[3]: width
// mods[4]: precision

static unsigned int	ft_flags(const char *s, t_storage *store, va_list *args)
{
	size_t	i;

	i = 0;
	i += ft_flag_mods(&s[i], store);
	i += ft_precision(&s[i], store);
	if (s[i] == 'c' && ++i)
		ft_print_char(va_arg(*args, int), store);
	else if (s[i] == 's' && ++i)
		ft_print_str(va_arg(*args, char *), store);
	else if (s[i] == 'p' && ++i)
		ft_print_void(va_arg(*args, void *), store);
	else if ((s[i] == 'i' || s[i] == 'd') && ++i)
		ft_print_int(va_arg(*args, int), store);
	else if (s[i] == 'u' && ++i)
		ft_print_uint(va_arg(*args, unsigned int), store);
	else if ((s[i] == 'x' || s[i] == 'X') && ++i)
		ft_print_hex(va_arg(*args, unsigned int), store, s[i - 1]);
	else
		i += ft_empty_flag(&s[i], store);
	return (i);
}

static void	ft_read(const char *s, va_list *args, t_storage *store)
{
	char	perc;

	perc = '%';
	store->read = 0;
	while (s[store->read])
	{
		if (s[store->read] == '%' && ++store->read)
		{
			if (s[store->read] == '%' && store->read++)
				store->count += write(1, &perc, 1);
			else
				store->a = 0;
				store->b = 0;
				store->c = 0;
				store->w = 0;
				store->p = -1;
				store->read += ft_flags(&s[store->read], store, args);
		}
		if (s[store->read] && s[store->read] != '%')
			store->count += write(1, &s[store->read++], 1);
	}
}

int	ft_printf(const char *s, ...)
{
	t_storage	*store;
	t_storage	storage;
	va_list		args;

	store = &storage;
	store->count = 0;
	va_start(args, s);
	ft_read(s, &args, store);
	va_end(args);
	return (store->count);
}
