/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:58:09 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:06:07 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_substr(char const *s, char *substr,
unsigned int start, size_t len)
{
	int		i;
	int		substr_len;

	substr_len = 1;
	if (start >= ft_strlen(s))
		substr_len = 0;
	i = 0;
	while (substr_len != 0 && len > 0 && s[start] != '\0')
	{
		substr[i] = s[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;

	if (s == 0)
		return (0);
	if (start < ft_strlen(s))
		substr_len = ft_strlen(s) - start;
	else
		substr_len = 0;
	if (substr_len < len)
		substr = malloc(substr_len + 1);
	else
		substr = malloc(len + 1);
	if (substr <= 0)
		return (0);
	return (ft_fill_substr(s, substr, start, len));
}
