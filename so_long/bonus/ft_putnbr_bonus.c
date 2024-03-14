/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:41:15 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 16:53:27 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putnbr(int i)
{
	int		n;

	n = i;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
		ft_putnbr(i);
	}
	else
	{
		if (i >= 10)
		{
			ft_putnbr(i / 10);
			ft_putnbr(i % 10);
		}
		else
			write(1, &(char){(char)(i + 48)}, 1);
	}
}
