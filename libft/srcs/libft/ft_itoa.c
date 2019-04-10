/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:15:34 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:15:35 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_len(int n)
{
	int size;

	size = 0;
	(n < 0) ? size++ : size;
	while (n /= 10)
		size++;
	return (size);
}

static	char	*ft_recur(char *s, long n, int i)
{
	if (n < 0 && (n = -n))
		s[0] = '-';
	(n >= 10) ? ft_recur(s, n / 10, i - 1) : 0;
	s[i] = (n % 10 + '0');
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		size;
	long	nb;

	nb = n;
	size = ft_len(n);
	if (!(s = (char*)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	ft_recur(s, nb, size);
	s[size + 1] = '\0';
	return (s);
}
