/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:17:13 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:17:13 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab_nb(int *tab, int len)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (i < len)
	{
		ft_putnbr(tab[i++]);
		ft_putchar('\n');
	}
}
