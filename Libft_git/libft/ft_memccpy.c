/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:39:17 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/15 17:57:42 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int ch, size_t nb)
{
	char	*ch1;
	char	*ch2;
	int		i;

	ch1 = (char*)dst;
	ch2 = (char*)src;
	i = 0;
	while (nb >= 1)
	{
		ch1[i] = ch2[i];
		if (ch2[i] == (char)ch)
			return (&ch1[i + 1]);
		i++;
		nb--;
	}
	return (NULL);
}
