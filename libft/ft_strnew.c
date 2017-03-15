/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:22:30 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/21 15:06:52 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char*)malloc(sizeof(char) * size + 1);
	if (arr == NULL)
		return (NULL);
	while (i <= size)
	{
		arr[i] = '\0';
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
