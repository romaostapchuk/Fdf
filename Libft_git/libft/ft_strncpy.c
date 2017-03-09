/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:28:53 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/15 17:45:35 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *temp;

	temp = dst;
	while (len > 0 && *src)
	{
		*temp++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*temp++ = '\0';
		len--;
	}
	return (dst);
}
