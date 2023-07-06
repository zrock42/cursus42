/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:40:51 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:41 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printuint(int nb, t_storage *store)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_uitoa(nb);
	store->p = -1;
	ft_print_str(&s[i], store);
	free(s);
	return ;
}
