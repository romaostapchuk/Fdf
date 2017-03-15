/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:33:40 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/21 15:20:39 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (s)
	{
		arr = (char*)malloc(sizeof(char) * len + 1);
		if (arr != NULL)
		{
			while (start > 0)
			{
				s++;
				start--;
			}
			while (i < len)
			{
				arr[i] = *s;
				i++;
				s++;
			}
			arr[i] = '\0';
			return (arr);
		}
	}
	return (NULL);
}
