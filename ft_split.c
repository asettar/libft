/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:44:51 by asettar           #+#    #+#             */
/*   Updated: 2022/10/16 23:46:54 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0 ;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			cnt++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cnt);
}

static int	word_len(char const *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	arr_clear(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
}

static void	ft_split_utils(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			arr[j] = (char *)malloc(word_len(s, i, c) + 1);
			if (!arr[j])
				arr_clear(arr);
			while (s[i] && s[i] != c)
				arr[j][k++] = s[i++];
			arr[j++][k] = 0;
		}
	}
	arr[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((num_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	ft_split_utils(arr, s, c);
	return (arr);
}
