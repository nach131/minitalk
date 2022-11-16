/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/16 21:04:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

static int	send_signal(const int pid, char ch)
{
	int	i;
	int send;

	i = 7;
	send = 0;
	ft_printf(ORANGE"'%c' \u2911  "WHITE, ch);
	while (i >= 0)
	{
		if (((ch >> i) & 1) == 1)
		{
			ft_printf(CYAN"1");
			kill(pid, SIGUSR1);
			send++;
		}
		else
		{
			ft_printf(CYAN"0");
			kill(pid, SIGUSR2);
			send++;
		}
		i--;
		usleep(200); // AUMENTAR SI SE PIERDEN BITE
	}
	ft_printf("\n");
	return(send);
}

static void print_line(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_printf(CYAN"\u2550");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	int send;

	send = 0;
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
		send += send_signal(pid, argv[2][i]);
		i++;
	}
	print_line(15);
	ft_printf("\n");
	ft_printf(GREEN"%d bits have been successfully sent.\n", send);

	return(0);
}

