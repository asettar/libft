/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:20:18 by asettar           #+#    #+#             */
/*   Updated: 2022/10/13 21:37:01 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	i;
	size_t	j;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dst);
	if (dlen >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = 0;
	j = dlen;
	while (src[i] && i < dstsize - dlen - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ft_strlen(src) + dlen);
}
