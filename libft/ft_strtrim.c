/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:39:58 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/15 16:29:29 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*str;
	unsigned int		beg;
	unsigned int		end;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		beg = 0;
		end = ft_strlen(s) - 1;
		while ((s[beg] == ' ' || s[beg] == '\t' || s[beg] == '\n')
				&& beg < end + 1)
			beg++;
		while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
				&& &s[end] != s)
			end--;
		if (beg >= end || beg == ft_strlen(s))
			return (ft_strnew(1));
		if ((str = ft_strnew(end - beg + 1)))
		{
			ft_strncpy(str, s + beg, end - beg + 1);
			return (str);
		}
	}
	return (NULL);
}
