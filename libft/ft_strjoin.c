/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:31:45 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/27 19:27:17 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
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
