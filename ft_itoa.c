/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:45:05 by asettar           #+#    #+#             */
/*   Updated: 2022/10/16 22:11:57 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	nb;

	nb = n;
	len = num_len(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	i = 0;
	if (nb < 0)
	{
		str[0] = '-';
		i++;
		nb *= -1;
	}
	while (len >= i)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
