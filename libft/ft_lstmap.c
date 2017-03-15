/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:29:40 by rostapch          #+#    #+#             */
/*   Updated: 2016/12/06 16:55:05 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_pushback(t_list *lst, t_list *news)
{
	t_list	*temp;

	if (lst != NULL)
	{
		temp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = news;
		lst = temp;
	}
	else
		lst = news;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*current;
	t_list	*temp;

	current = lst;
	ret = NULL;
	while (current)
	{
		temp = f((t_list*)current);
		ret = ft_pushback(ret, ft_lstnew(temp->content, temp->content_size));
		current = current->next;
	}
	return (ret);
}
