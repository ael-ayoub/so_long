/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:08 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/01 09:34:25 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	len_find;

	if (*to_find == 0)
		return ((char *)str);
	len_find = ft_strlen(to_find);
	while (*str && len >= len_find)
	{
		if (ft_strncmp(str, to_find, len_find) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (0);
}
