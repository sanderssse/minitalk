/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:12:08 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/11 23:05:57 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (copy == 0)
		return (0);
	i = 0;
	while (len > 0)
	{
		copy[i] = s1[i];
		len--;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
