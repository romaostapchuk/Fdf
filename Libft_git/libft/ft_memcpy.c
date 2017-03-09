/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:13:51 by rostapch          #+#    #+#             */
/*   Updated: 2016/11/22 14:17:00 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict s1,
				const void *restrict s2, size_t nb)
{
	unsigned char *ch1;
	unsigned char *ch2;

	ch1 = (unsigned char *)s1;
	ch2 = (unsigned char *)s2;
	while (nb >= 1)
	{
		*ch1++ = (unsigned char)*ch2++;
		nb--;
	}
	return ((unsigned char *)s1);
}
