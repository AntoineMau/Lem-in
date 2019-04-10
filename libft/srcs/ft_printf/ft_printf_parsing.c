/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffret@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:04:07 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/20 11:11:40 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

t_printf		*ft_printf_parsing(t_printf *p, const char *format)
{
	while (format[p->index]
		&& !(ft_strrchr("spdiouxXcf%", format[p->index])))
	{
		if (ft_strrchr("hlL", format[p->index]))
			ft_printf_get_modifier(p, format);
		else if (ft_strrchr("#0-+ ", format[p->index]))
			ft_printf_get_flag(p, format);
		else if (format[p->index] == '.')
			ft_printf_get_precision(p, format);
		else if ((format[p->index] != '0'
		&& ft_isdigit((__int32_t)format[p->index])))
			ft_printf_get_champ(p, format);
		else
			break ;
	}
	ft_printf_get_conv(p, format);
	if (!format[p->index] && (p->error = -1))
		return (p);
	if ((int)p->conv == (int)FT_PRINTF_NO_MODIFIERS)
		p->tmpchar = format[p->index];
	++p->index;
	return (p);
}
