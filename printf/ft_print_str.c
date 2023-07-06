/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:06:33 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:36 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printstr(char *s, t_storage *store)
{
	ssize_t	len;
	char	fill;

	fill = ' ';
	if (store->c == 1)
		fill = '0';
	len = ft_strlen(s);
	if (store->p != -1 && len > store->p)
		len = store->p;
	if (len < store->w)
	{
		store->w -= len;
		if (store->c == 2)
			store->count += write(1, s, len);
		while (store->w--)
			store->count += write(1, &fill, 1);
		if (store->c == 0 || store->c == 1)
			store->count += write(1, s, len);
	}
	else
		store->count += write(1, s, len);
	return ;
}
