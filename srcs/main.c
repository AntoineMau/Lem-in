/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:16:28 by anmauffr          #+#    #+#             */
/*   Updated: 2019/04/25 13:05:32 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	ft_lstfree(t_lemin *lemin)
{
	int		i;

	i = 0;
	while (lemin->file[i])
		free(lemin->file[i++]);
}

int		parsing(t_lemin *lemin)
{
	int		ret;
	char	*file;
	char	*tmp;
	char	*line;

	file = (char*)malloc(1);
	file[0] = '\0';
	while ((ret = get_next_line(0, &line)) > 0)
	{
		tmp = ft_strjoin(file, line);
		free(file);
		file = ft_strjoin(tmp, "\n");
		free(line);
		free(tmp);
	}
	if (ret != 0)
	{
		free(file);
		return (FALSE);
	}
	lemin->file = ft_strsplit(file, '\n');
	free(file);
	ft_printtab_str(lemin->file);
	return (TRUE);
}

int		main(void)
{
	t_lemin	lemin;

	if (!parsing(&lemin))
		return (0);
	ft_lstfree(&lemin);
	return (1);
}
