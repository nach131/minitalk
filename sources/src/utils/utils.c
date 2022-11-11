/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/11 20:45:11 by nmota-bu         ###   ########.fr       */
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

// int	ft_find_bit(unsigned char octet)
// {
// 	int	i;
// 	char
// }

void	ft_spinner(void)
{
	char	arrows[4] = { '|' , '/', '-', '\\' };
	int		i;

	i = 0;
	while (1)
	{
		write(1, &arrows[i], 1);
		fflush(stdout);
		i++;
		if (i > 3)
			i = 0;
		usleep(100000);
		write(1, "\b", 1);
	}
}

void	ft_process_bar(void)
{
	char arrows[6][12] = {
"(-o--------)" ,
"(-----o----)",
"(---------o)",
"(--------o-)",
"(---o------)",
"(o---------)" };

	int		i;
	int		j;

	i = 0;
	while (1)
	{
		write(1, &arrows[i], 12);
		i++;
		if (i > 5)
			i = 0;
		usleep(200000);
		j = 0;
		while (j < 15)
		{
			write(1, "\b", 1);
			j++;
		}
	}
}

