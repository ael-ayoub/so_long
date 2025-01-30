/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:40:36 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/10/31 15:21:36 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_w(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

int	len_w(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	*save_w(char const *str, char c)
{
	int		len;
	char	*word;
	int		i;

	len = len_w(str, c);
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		i;

	if (!s)
		return (0);
	ss = (char **)malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!ss)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			ss[i] = save_w(s, c);
			if (!ss[i])
				return (free_array(ss, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	ss[i] = 0;
	return (ss);
}
