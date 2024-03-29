/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:18:58 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:18:58 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char *s, char c, size_t size)
{
	size_t		i;

	i = 0;
	while (s && i < size)
		s[i++] = c;
	return (s);
}
