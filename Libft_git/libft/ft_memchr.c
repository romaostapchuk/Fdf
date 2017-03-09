/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:59:02 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/15 17:47:41 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int ch, size_t nb)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (nb >= 1)
	{
		if (*str == (unsigned char)ch)
			return (str);
		str++;
		nb--;
	}
	return (NULL);
}
