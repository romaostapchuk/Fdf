/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:31:45 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/21 15:34:15 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	size_t	i;

	i = -1;
	if (s1 && s2)
	{
		arr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (arr == NULL)
			return (NULL);
		while (s1[++i])
			arr[i] = s1[i];
		while (*s2)
			arr[i++] = *s2++;
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}
