/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:11:59 by asettar           #+#    #+#             */
/*   Updated: 2022/10/13 21:37:31 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	char	*dlast;
	char	*slast;

	if (!src && !dst)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		dlast = d + len - 1;
		slast = s + len - 1;
		while (len --)
			*dlast-- = *slast--;
	}
	return (dst);
}
