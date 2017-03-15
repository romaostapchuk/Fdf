/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:03:56 by rostapch          #+#    #+#             */
/*   Updated: 2017/01/17 17:03:57 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
