/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:48:11 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:03:30 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;
	char	*s1;

	s1 = (char *)s;
	c1 = (char)c;
	i = 0;
	if (c1 == 0)
		return (&s1[ft_strlen(s1)]);
	while (s1[i] != '\0')
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	return (0);
}
