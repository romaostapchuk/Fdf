/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:32:41 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/21 15:17:45 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && n > i)
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
				return (0);
			i++;
		}
		if ((unsigned char)s1[i] - (unsigned char)s2[i]
					&& (i != (unsigned int)n))
			return (0);
		else
			return (1);
	}
	return (0);
}
