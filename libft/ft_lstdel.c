/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:51:38 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/06 15:59:18 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *next;

	current = *alst;
	next = NULL;
	while (current)
	{
		next = current->next;
		del(current->content, current->content_size);
		free(current);
		current = next;
	}
	*alst = NULL;
}
