/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:18:50 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/05 09:05:28 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_space(const char *str, int *p)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*p = i;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	nbr;

	s = ft_space(str, &i);
	nbr = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	nbr = nbr * s;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (-1);
	return (nbr);
}
