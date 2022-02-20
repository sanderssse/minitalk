/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:26:04 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:05:53 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_find_first_char(char const *s1, char const *set)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
		j = 0;
	}
	return (i);
}

static	int	ft_find_last_char(char const *s1, char const *set)
{
	int		i;
	size_t	j;

	if (ft_strlen(s1) == 0)
		return (0);
	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0)
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i--;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
		j = 0;
	}
	return (i);
}

static char	*ft_fill_string(char const *s1, char *s2,
int first_char, int last_char)
{
	unsigned long int	i;

	i = 0;
	while (first_char <= last_char)
	{
		s2[i] = s1[first_char];
		i++;
		first_char++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*s2;
	int					first_char;
	int					last_char;

	if (s1 == 0)
		return (0);
	first_char = ft_find_first_char(s1, set);
	last_char = ft_find_last_char(s1, set);
	if (last_char - first_char >= 0)
		s2 = malloc(last_char - first_char + 2);
	else
	{
		s2 = malloc(1);
		s2[0] = '\0';
		return (s2);
	}
	if (s2 <= 0)
		return (0);
	return (ft_fill_string(s1, s2, first_char, last_char));
}
