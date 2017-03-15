/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:03:43 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/03 19:29:38 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_int_length(int nb)
{
	int len;

	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char			*ft_fill_arr(int nb, int len)
{
	char	*numb;
	int		neg;

	neg = 0;
	if (nb < 0)
	{
		numb = (char*)malloc(sizeof(char) * len++ + 2);
		neg = 1;
		nb *= -1;
	}
	if (nb >= 0)
		numb = (char*)malloc(sizeof(char) * len + 1);
	if (!numb)
		return (NULL);
	numb[len--] = '\0';
	while (nb > 0)
	{
		numb[len--] = '0' + nb % 10;
		nb /= 10;
	}
	if (neg == 1)
		numb[0] = '-';
	return (numb);
}

char				*ft_itoa(int n)
{
	char	*numb;

	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	numb = ft_fill_arr(n, ft_int_length(n));
	return (numb);
}
