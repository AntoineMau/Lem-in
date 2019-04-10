/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:16:28 by anmauffr          #+#    #+#             */
/*   Updated: 2019/04/10 20:55:47 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		main(void)
{
	char	*line;

	dprintf(1, "Bonjour1");
	while (get_next_line(0, &line) == 1)
	{
		ft_printf("%s\n", line);
		free(line);
	}
	return (0);
}
