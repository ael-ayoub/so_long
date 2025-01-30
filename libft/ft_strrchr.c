/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:11 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/01 18:12:45 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	c = (char)c;
	if (c == '\0')
		return (ft_strlen(s) + (char *)s);
	ptr = NULL;
	while (*s)
	{
		if (c == *s)
			ptr = (char *)s;
		s++;
	}
	return (ptr);
}
