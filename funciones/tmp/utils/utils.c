/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/18 23:18:33 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

void	ft_print_bits(unsigned char octet)
{
	int		i;
	char	bits;

	i = 7;
	while (i >= 0)
	{
		bits = ((octet >> i) & 1) + '0';
		ft_printf(GREEN"%c", bits);
		i--;
	}
}

void	ft_process_bar(void)
{
	int i = 0;
	char *arrows[5];

	arrows[0] = "\u25aa";
	arrows[1] = "\u25fc";
	arrows[2] = "\u2588";
	arrows[3] = "\u25fc";
	arrows[4] = "\u25aa";

	while (1)
	{
		ft_printf(RED"%c", arrows[i]);
		i++;
		if (i > 4)
			i = 0;

		usleep(200000);
		write(1, "\b", 1);
	}
}
