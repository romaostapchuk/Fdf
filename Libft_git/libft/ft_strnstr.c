/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:18:26 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/09 13:18:28 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t len;

	if (!*needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	n++;
	while (--n && *haystack)
	{
		if (len > n)
			return (NULL);
		if (!ft_strncmp(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
