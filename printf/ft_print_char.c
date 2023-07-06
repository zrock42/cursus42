/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:18 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:18 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printchar(int c, t_storage *store)
{
	char	to_print;
	char	fill;

	to_print = c;
	if (store->w > 1)
	{
		store->w--;
		fill = ' ';
		if (store->b == 1)
			fill = '0';
		if (store->b == 2)
			store->count += write(1, &to_print, 1);
		while (store->w--)
			store->count += write(1, &fill, 1);
		if (store->b == 0 || store->b == 1)
			store->count += write(1, &to_print, 1);
	}
	store->count += write(1, &to_print, 1);
	return ;
}
