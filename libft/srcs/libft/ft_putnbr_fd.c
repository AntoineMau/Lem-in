/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:17:48 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:17:48 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	long	nb;

	nb = n;
	(nb < 0 && (nb = -nb) ? ft_putchar_fd('-', fd) : nb);
	(nb >= 10) ? ft_putnbr_fd(nb / 10, fd) : nb;
	ft_putchar_fd(nb % 10 + '0', fd);
}
