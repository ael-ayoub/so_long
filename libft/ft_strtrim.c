/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:14 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/01 20:10:28 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*start;
	char	*trimed;
	int		len;

	start = (char *)s1;
	while (*start && whitespace((char *)set, *start) == 0)
		start++;
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (end > start && whitespace((char *)set, *end) == 0)
		end--;
	len = end - start + 1;
	trimed = (char *)malloc(len + 1);
	if (!trimed)
		return (NULL);
	ft_strlcpy(trimed, start, len + 1);
	return (trimed);
}
