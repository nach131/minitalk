/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/14 23:17:59 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

// static void	send_signal(const int pid, char *str)
// {
// 	int	i;
// 	int	bit;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		ft_printf(ORANGE"'%c' --> "WHITE, str[i]);
// 		bit = 7;
// 		while (bit >= 0)
// 		{
// 			if (((str[i] >> bit) & 1) == 1)
// 			{
// 				ft_printf(CYAN"1");
// 				kill(pid, SIGUSR1);
// 			}
// 			else
// 			{
// 				ft_printf(CYAN"0");
// 				kill(pid, SIGUSR2);
// 			}
// 			bit--;
// 			usleep(200); // AUMENTAR SI SE PIERDEN BITE
// 		}
// 		i++;
// 		ft_printf("\n");
// 	}
// }

static void	send_signal(const int pid, char str)
{
	int	i;

	i = 7;
	ft_printf(ORANGE"'%c' --> "WHITE, str);
	while (i >= 0)
	{
		if (((str >> i) & 1) == 1)
			{
				ft_printf(CYAN"1");
				kill(pid, SIGUSR1);
			}
			else
			{
				ft_printf(CYAN"0");
				kill(pid, SIGUSR2);
			}
		i--;
			usleep(200); // AUMENTAR SI SE PIERDEN BITE
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;

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
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}

	return(0);
}

