/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:19:26 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:19:26 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*snew;
	size_t			i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (!(snew = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		snew[i] = f(j, s[i]);
		i++;
		j++;
	}
	snew[i] = '\0';
	return (snew);
}
