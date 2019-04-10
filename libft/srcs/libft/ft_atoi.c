/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:14:37 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:14:42 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nb;
	int i;
	int neg;

	neg = 0;
	i = 0;
	nb = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = (nb * 10) + (str[i] - '0');
			i++;
		}
	if (neg == 1)
		nb *= -1;
	return (nb);
}
