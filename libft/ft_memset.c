/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:22:16 by rostapch          #+#    #+#             */
/*   Updated: 2017/01/28 17:16:24 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int val, size_t nb)
{
	unsigned char	*chr;
	int				i;

	i = 0;
	chr = (unsigned char *)str;
	while (nb >= 1)
	{
		chr[i] = (unsigned char)val;
		i++;
		nb--;
	}
	return (str);
}
