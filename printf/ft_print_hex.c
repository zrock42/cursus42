/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:16:45 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:28 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	convert(unsigned int nb, char *result,
						ssize_t precision, char x)
{
	int		i;
	char	base[16];

	if (x == 'x')
		ft_memcpy(base, "0123456789abcdef", 16);
	else
		ft_memcpy(base, "0123456789ABCDEF", 16);
	i = 0;
	if (nb == 0)
		result[i++] = '0';
	while (nb > 0)
	{
		result[i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	result[i] = '\0';
	if (precision > i)
		return (precision - i);
	else if (precision == -1)
		return (-1);
	return (0);
}

static void	flip(char *result)
{
	int		len;
	int		i;
	char	cc;

	len = 0;
	while (result[len] != '\0')
		len++;
	len--;
	i = 0;
	while (i < len)
	{
		cc = result[i];
		result[i++] = result[len];
		result[len--] = cc;
	}
	return ;
}

static void	print1(char *result, t_storage *store, char x)
{
	int	len;

	len = ft_strlen(result);
	if (store->a)
		store->w -= 2;
	if (store->c == 0)
		while (store->w-- > len)
			store->count += write(1, " ", 1);
	if (store->a)
	{
		store->count += 2;
		if (x == 'x')
			write(1, "x0", 2);
		else
			write(1, "X0", 2);
	}
	if (store->c == 1)
		while (store->w-- > len)
			store->count += write(1, "0", 1);
	store->count += write(1, result, len);
	if (store->c == 2)
		while (store->w-- > len)
			store->count += write(1, " ", 1);
}

static void	print2(char *result, t_storage *store, char x)
{
	int	len;
	int	i;

	len = ft_strlen(result);
	if (store->a)
		store->w -= 2;
	if (store->c == 0 || store->c == 1)
		while (store->w-- > store->p + len)
			store->count += write(1, " ", 1);
	if (store->a)
	{
		store->count += 2;
		if (x == 'x')
			write(1, "x0", 2);
		else
			write(1, "X0", 2);
	}
	i = 0;
	while (i++ < store->p)
		store->count += write(1, "0", 1);
	store->count += write(1, result, len);
	if (store->c == 2)
		while (store->w-- > store->p + len)
			store->count += write(1, " ", 1);
}

void	ft_print_hex(unsigned int nb, t_storage *store, char x)
{
	char	result[14];

	store->p = convert(nb, result, store->p, x);
	flip(result);
	if (store->p == -1)
		print1(result, store, x);
	else
		print2(result, store, x);
	return ;
}
