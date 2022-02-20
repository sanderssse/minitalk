/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:39:22 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/10 20:21:45 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	char			*b1;
	unsigned char	c1;

	c1 = c;
	b1 = (char *)b;
	i = 0;
	while (len > 0)
	{
		b1[i] = c1;
		i++;
		len--;
	}
	return (b1);
}
