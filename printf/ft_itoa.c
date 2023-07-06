/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrock <zrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:44:47 by zrock             #+#    #+#             */
/*   Updated: 2023/03/30 19:02:20 by zrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*zero(void)
{
	char	*s;

	s = (char *)malloc(2);
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static char	*build(unsigned int n, int neg)
{
	int		i;
	int		j;
	char	*s;
	char	store[12];

	i = 0;
	while (n > 0)
	{
		store[i++] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		store[i++] = '-';
	s = (char *)malloc(i + 1);
	if (!s)
		return (NULL);
	j = 0;
	while (i--)
		s[j++] = store[i];
	s[j] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	unsigned int	n_plus;
	int				neg;

	neg = 0;
	if (n == 0)
		return (zero());
	if (n < 0)
	{
		neg = 1;
		n_plus = n * -1;
	}
	else
		n_plus = n;
	return (build(n_plus, neg));
}	
