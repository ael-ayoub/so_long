/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:38:57 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/01 20:27:39 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lengh(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*nbr;
	int		len;

	nb = n;
	len = lengh(nb);
	nbr = (char *)malloc(len + 1);
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	if (nb == 0)
		nbr[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		nbr[0] = '-';
	}
	while (nb > 0)
	{
		nbr[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (nbr);
}
