/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:03:18 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:03:19 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

void		ft_printf_display(t_printf *p, const char *format)
{
	size_t		buf;

	while (format[p->index])
	{
		buf = ft_strclen(&format[p->index], '%');
		write(1, &format[p->index], buf);
		p->ret += buf;
		p->index += buf;
		if (format[p->index] == '%')
		{
			if (!format[++p->index])
				break ;
			p = ft_printf_parsing(p, format);
			if (p->error)
				break ;
			p = ft_printf_conv(p);
			if (p->error)
				break ;
			reset_t_printf(p);
		}
	}
}
