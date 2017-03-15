/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:20:01 by rostapch          #+#    #+#             */
/*   Updated: 2016/11/24 19:27:05 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *target)
{
	char *p1begin;
	char *p2;
	char *p1;

	if (!*target)
		return ((char *)str);
	p1 = (char *)str;
	while (*p1)
	{
		p1begin = p1;
		p2 = (char*)target;
		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (!*p2)
			return (p1begin);
		p1 = p1begin + 1;
	}
	return (NULL);
}
