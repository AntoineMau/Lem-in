/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:18:53 by anmauffr          #+#    #+#             */
/*   Updated: 2019/04/25 11:39:53 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // pour perror et peut etre rajouter errno.h
# include <string.h> // pour strerror

# define TRUE 1
# define FALSE 0

typedef struct	s_lemin
{
	char	**file;
}				t_lemin;

#endif