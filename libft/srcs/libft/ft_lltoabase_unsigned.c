/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoabase_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:15:47 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:15:48 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoabase_unsigned(unsigned long long nbr, int base)
{
	char			*s;
	char			tmp;

	s = ft_strnew(0);
	if (!nbr)
		s = ft_stradd_leakless(s, '0');
	while (nbr && base > 1 && base < 37)
	{
		tmp = (char)(nbr % (unsigned)base);
		if (tmp > 9)
			tmp += 'a' - 10;
		else
			tmp += '0';
		s = ft_stradd_leakless(s, (char)tmp);
		nbr /= (unsigned)base;
	}
	return ((s = ft_strrev_leakless(s)));
}
