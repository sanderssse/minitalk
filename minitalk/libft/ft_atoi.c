/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:52 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:01:10 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_deal_with_overlong(int m)
{
	if (m > 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long		res;
	int						m;

	m = 0;
	res = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			m++;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > __LONG_LONG_MAX__)
		return (ft_deal_with_overlong(m));
	if (m)
		return (-res);
	return (res);
}
