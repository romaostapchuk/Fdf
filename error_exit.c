/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:38:53 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/16 13:38:55 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(int err)
{
	if (err == -1)
		perror("Error opening file");
	else if (err == 2)
		write(1, "Error: not correct projection", 29);
	exit(0);
}
