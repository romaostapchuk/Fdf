/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:26:14 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/06 15:01:15 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t nb)
{
	size_t	i;

	if (s1 == s2)
		return (s1);
	else if (s2 < s1)
	{
		i = nb + 1;
		while (--i)
		{
			*((char *)(s1 + i - 1)) = *(char *)(s2 + i - 1);
		}
	}
	else
	{
		i = -1;
		while (++i < nb)
		{
			*((char *)(s1 + i)) = *((char *)(s2 + i));
		}
	}
	return (s1);
}
