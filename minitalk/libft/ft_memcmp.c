/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:49:34 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:02:11 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mys1;
	unsigned char	*mys2;
	int				i;

	mys1 = (unsigned char *)s1;
	mys2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (mys1[i] != mys2[i])
			return (mys1[i] - mys2[i]);
		i++;
		n--;
	}
	return (0);
}
