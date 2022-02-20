/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:32:55 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:04:37 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char			*dst1;
	unsigned int	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst1 = (char *)dst;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(dst) + 1);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst1[i] = src[i];
		i++;
	}
	dst1[i] = '\0';
	if (dstsize <= ft_strlen(src))
		return (ft_strlen(src));
	if (i < ft_strlen(dst))
		return (ft_strlen(dst) + 1);
	return (i);
}
