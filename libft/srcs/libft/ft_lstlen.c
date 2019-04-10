/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:31:02 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:31:03 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *beg)
{
	t_list		*tmp;
	int			i;

	i = 0;
	if (beg == NULL)
		return (0);
	tmp = beg;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
