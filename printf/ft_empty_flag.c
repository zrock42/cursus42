/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:05:21 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:01:46 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	ft_empty_flag(const char *s, t_storage *store)
{
	write(1, "Empty % sign, fool", 18);
	store->count = -1;
	return (ft_strlen(s));
}
