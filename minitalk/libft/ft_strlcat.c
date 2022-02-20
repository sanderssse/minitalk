/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:29:18 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:04:21 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*dst1;
	char			*src1;
	int				appendsize;
	size_t			dstlen;
	size_t			i;

	dst1 = (char *)dst;
	src1 = (char *)src;
	appendsize = dstsize - ft_strlen(dst1) - 1;
	dstlen = ft_strlen(dst1);
	i = 0;
	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	while (appendsize != 0 && src1[i] != '\0')
	{
		dst1[i + dstlen] = src1[i];
		i++;
		appendsize--;
	}
	dst1[i + dstlen] = '\0';
	return (dstlen + ft_strlen(src));
}
