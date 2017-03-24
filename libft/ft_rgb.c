/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:57:40 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/24 19:01:31 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_rgb(int red, int green, int blue)
{
	red = (red << 16) & 0xFF0000;
	green = (green << 8) & 0x00FF00;
	blue = (blue) & 0x0000FF;

	return (red | green | blue);
}