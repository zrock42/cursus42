/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:42:29 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:32 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printint(int nb, t_storage *store)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_itoa(nb);
	store->p = -1;
	if (store->b == 1 && *s != '-')
		store->count += write(1, " ", 1);
	else if (store->b == 2 && *s != '-')
		store->count += write(1, "+", 1);
	else if (*s == '-')
		store->count += write(1, &s[i++], 1);
	ft_print_str(&s[i], store);
	free(s);
	return ;
}
