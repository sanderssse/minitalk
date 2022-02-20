/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:01:29 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:02:33 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*src1;
	char			*dst1;

	i = 0;
	if (dst > src)
	{
		src1 = (char *)src + len - 1;
		dst1 = (char *)dst + len - 1;
		while (len--)
			*dst1-- = *src1--;
	}
	else if (dst < src)
	{
		src1 = (char *)src;
		dst1 = (char *)dst;
		while (len--)
			*dst1++ = *src1++;
	}
	return (dst);
}
