/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:23:54 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/06 14:26:28 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_amount(char const *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int		ft_word_length(char const *str, char c, int index)
{
	int len;

	len = 0;
	while (str[index] != c && index >= 0)
	{
		len++;
		index--;
	}
	return (len);
}

static void		ft_fill_array(char const *str, char *arr, int len, int index)
{
	int i;

	i = 0;
	arr[len] = '\0';
	len--;
	while (len >= 0)
	{
		arr[len] = str[index - i];
		i++;
		len--;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**arr;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	arr = (char**)malloc(sizeof(char*) * ft_word_amount(s, c) + 1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			arr[k] = (char*)malloc(sizeof(char) * ft_word_length(s, c, i) + 1);
			ft_fill_array(s, arr[k], ft_word_length(s, c, i), i);
			k++;
		}
		i++;
	}
	arr[k] = NULL;
	return (arr);
}
