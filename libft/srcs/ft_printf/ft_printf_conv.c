/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:03:09 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:04:35 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

t_printf		*ft_printf_conv(t_printf *p)
{
	__int32_t	i;

	i = 0;
	while (i < 9 && !p->error)
		p = p->tab_ptr[i++](p);
	return (p);
}
