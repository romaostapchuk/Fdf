/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:27:56 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/21 15:12:39 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*arr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	arr = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (arr == NULL)
		return (NULL);
	while (s[i])
	{
		arr[i] = f(s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
