/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:27:19 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/21 15:01:33 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sub_s1;
	unsigned char	*sub_s2;
	size_t			i;

	if (n == 0)
		return (0);
	sub_s1 = (unsigned char*)s1;
	sub_s2 = (unsigned char*)s2;
	i = 0;
	while (++i < n && *sub_s1 == *sub_s2 && *sub_s1 && sub_s2)
	{
		sub_s1++;
		sub_s2++;
	}
	return (*sub_s1 - *sub_s2);
}
