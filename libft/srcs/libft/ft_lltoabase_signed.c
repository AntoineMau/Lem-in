/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoabase_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:15:39 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:15:39 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoabase_signed(long long nbr, int base)
{
	unsigned long long		nb;
	char					*s;
	int						neg;
	char					tmp;

	neg = 0;
	s = ft_strnew(0);
	nb = (unsigned long long)nbr;
	if (nbr < 0 && (++neg))
		nb = (unsigned long long)-nbr;
	if (!nb)
		return ((s = ft_stradd_leakless(s, '0')));
	while (nb && base > 1 && base < 37)
	{
		tmp = (char)(nb % (unsigned long long)base);
		if (tmp > 9)
			tmp += 'a' - 10;
		else
			tmp += '0';
		s = ft_stradd_leakless(s, tmp);
		nb /= (unsigned long long)base;
	}
	if (neg)
		s = ft_stradd_leakless(s, '-');
	return ((s = ft_strrev_leakless(s)));
}
