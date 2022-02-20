/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:23:07 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:04:52 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*mys1;
	unsigned char	*mys2;

	mys1 = (unsigned char *)s1;
	mys2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (mys1[i] > mys2[i] || mys1[i] < mys2[i])
			return (mys1[i] - mys2[i]);
		if (mys1[i] == mys2[i] && mys1[i] == '\0')
			break ;
		i++;
		n--;
	}
	return (0);
}
