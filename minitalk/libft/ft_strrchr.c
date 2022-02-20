/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:12:47 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:05:25 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		c1;
	char	*s1;

	c1 = (char)c;
	s1 = (char *)s;
	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i--;
	}
	return (0);
}
