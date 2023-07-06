/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:01:54 by zrock             #+#    #+#             */
/*   Updated: 2023/03/05 21:01:54 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (((*s < 14 && *s > 8) || *s == 32))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result *= 10;
		result += *s - 48;
		s++;
	}
	return (result * sign);
}
