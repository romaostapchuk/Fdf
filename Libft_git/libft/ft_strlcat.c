/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:20:19 by rostapch          #+#    #+#             */
/*   Updated: 2016/11/24 21:24:16 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	unsigned int i;
	unsigned int ret;

	ret = ft_strlen(src) + size;
	i = ft_strlen(dst);
	if (ret > i + ft_strlen(src))
		ret = i + ft_strlen(src);
	while (*src && i < size - 1)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (ret);
}
