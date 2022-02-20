/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:37:34 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:05:09 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack1;
	size_t	needle_len;
	int		i;

	if (haystack == 0)
		i = haystack[ft_strlen(haystack) + 2];
	haystack1 = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (needle_len == 0)
		return (haystack1);
	if (len == 0)
		return (0);
	i = len - needle_len;
	while (i >= 0)
	{
		if (haystack1[0] == needle[0]
			&& !ft_strncmp(haystack1, needle, needle_len))
			return (haystack1);
		haystack1++;
		i--;
	}
	return (0);
}
