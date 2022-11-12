/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/12 11:41:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// #include "minitalk.h"

// ESTO PARA DEBUG VS
#include <stdio.h>
#include "../../inc/minitalk.h"
#include "../../libft/inc/libft.h"

static void	send_signal(const int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		ft_printf(ORANGE"'%c' --> "WHITE, str[i]);
		bit = 7;
		while (bit >= 0)
		{
			if (((str[i] >> bit) & 1) == 1)
			{
				ft_printf(CYAN"1");
				kill(pid, SIGUSR1);
			}
			else
			{
				ft_printf(CYAN"0");
				kill(pid, SIGUSR2);
			}
			bit--;
			usleep(2); // AUMENTAR SI SE PIERDEN BITE
		}
		i++;
		ft_printf("\n");
	}

}

int	main(int argc, char **argv)
{
	int	pid;
	(void)argv;

	if (argc <= 2)
	{
		ft_message(Danger, MSG_DAN_0);
		return(1);
	}
	else if (argc >= 4)
	{
		ft_message(Danger, MSG_DAN_1);
		return(1);
	}
	pid = ft_atoi(argv[1]);
	send_signal(pid, argv[2]);

	return(0);
}


