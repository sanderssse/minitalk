/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:48:29 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:01:48 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	i;

	if (n == -2147483648)
		return (10);
	i = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static int	ft_power_of_ten(int n)
{
	long long int	res;

	res = 10;
	while (n - 2 > 0)
	{
		res = res * 10;
		n--;
	}
	return (res);
}

static char	*ft_deal_with_minus(int n)
{
	char			*res;
	int				i;
	int				digits_num;

	digits_num = ft_countdigits(n);
	res = malloc(digits_num + 2);
	if (res <= 0)
		return (0);
	if (n == -2147483648)
		return (res = ft_memcpy(res, "-2147483648", 12));
	n = -n;
	res[0] = '-';
	i = 1;
	while (digits_num > 1)
	{
		res[i] = (n / (ft_power_of_ten(digits_num)) + '0');
		n = n % ft_power_of_ten(digits_num);
		digits_num--;
		i++;
	}
	res[i] = n + '0';
	res[i + 1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	int				digits_num;

	if (n < 0)
		return (ft_deal_with_minus(n));
	digits_num = ft_countdigits(n);
	res = malloc(digits_num + 1);
	if (res <= 0)
		return (0);
	i = 0;
	while (digits_num > 1)
	{
		res[i] = (n / (ft_power_of_ten(digits_num)) + '0');
		n = n % ft_power_of_ten(digits_num);
		digits_num--;
		i++;
	}
	res[i] = n + '0';
	res[i + 1] = '\0';
	return (res);
}
