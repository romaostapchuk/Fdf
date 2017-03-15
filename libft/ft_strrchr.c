/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:03:51 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/15 17:18:09 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		pos;
	int		i;

	i = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	if ((s[i] == (char)c) && ((char)c == '\0'))
		return ((char*)(s + i));
	if (pos == -1)
		return (NULL);
	return ((char*)(s + pos));
}
