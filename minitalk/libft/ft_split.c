/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:20:10 by xcharley          #+#    #+#             */
/*   Updated: 2021/10/23 20:00:42 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	ft_count_symbols(const char *s, char c)
{
	int	i;
	int	max;
	int	cur;

	i = 0;
	max = 0;
	cur = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			cur++;
			i++;
		}
		if (cur > max)
			max = cur;
		if (cur == 0)
			i++;
		cur = 0;
	}
	return (max);
}

static char	**ft_fill_array(char **arr, char const *s, char c)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (*s != '\0')
	{
		while (*s != c && *s)
		{
			arr[j][k] = *s;
			s++;
			k++;
		}
		if (k != 0)
		{
			arr[j][k] = '\0';
			j++;
			k = 0;
		}
		if (*s != '\0')
			s++;
	}
	arr[j] = 0;
	return (arr);
}

void	*ft_free_arr(char **arr, char const *s, char c)
{
	int	i;

	i = 0;
	while (i < ft_count_words(s, c) + 1)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (s == 0)
		return (0);
	i = 0;
	arr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (arr <= 0)
		return (0);
	while (i < ft_count_words(s, c))
	{
		arr[i] = malloc(ft_count_symbols(s, c) + 1);
		if (arr[i] <= 0)
			ft_free_arr(arr, s, c);
		i++;
	}
	return (ft_fill_array(arr, s, c));
}
