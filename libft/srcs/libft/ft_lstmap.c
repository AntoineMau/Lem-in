/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:16:19 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:16:19 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_elem;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	temp = f(lst);
	if (!(new = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	begin_elem = new;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(new->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin_elem);
}
