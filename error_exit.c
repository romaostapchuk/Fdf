/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:38:53 by rostapch          #+#    #+#             */
/*   Updated: 2017/04/02 20:02:28 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(int err)
{
	if (err == -1)
		perror("Error opening file");
	else if (err == 2)
		write(1, "Error: not correct projection", 29);
	else if (err == 3)
	{
		write(1, "Error: not enough arguments\n./fdf [file] [projection] ", 54);
		write(1, "(size xy) (size z)\n", 19);
	}
	else if (err == 4)
		write(1, "Error: empty file\n", 18);
	exit(1);
}
