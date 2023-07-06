/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:26:15 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:47 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_void(void *p, t_storage *store)
{
	unsigned long int	nb;

	if (!p)
		nb = 0;
	else
		nb = (unsigned long int)p;
	store->a = 1;
	store->b = 0;
	if (store->c != 2)
		store->c = 0;
	store->p = -1;
	ft_print_hex(nb, store, 'x');
	return ;
}
