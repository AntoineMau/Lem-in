/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:17:18 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:17:19 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab_str(char **str)
{
	int i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		ft_putendl(str[i]);
}
