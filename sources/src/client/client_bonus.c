/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/18 00:06:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

int	g_received;

static void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		usleep(200);
		g_received++;
	}
}

static int	send_signal(const int pid, char ch)
{
	int	i;
	int	send;

	i = 7;
	send = 0;
	ft_printf(ORANGE"'%c' \u2911  "WHITE, ch);
	while (i >= 0)
	{
		if (((ch >> i) & 1) == 1)
		{
			ft_printf(CYAN"1");
			if (kill(pid, SIGUSR1) == -1)
				ft_message(Warning, MSG_WAR_1);
			send++;
		}
		else
		{
			ft_printf(CYAN"0");
			if (kill(pid, SIGUSR2) == -1)
				ft_message(Warning, MSG_WAR_1);
			send++;
		}
		i--;
		usleep(200);
	}
	ft_printf("\n");
	return (send);
}

static void	print_line(int n)
{
	int	i;

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
	int	i;
	int	send;

	g_received = 0;
	send = 0;
	if (argc <= 2)
	{
		ft_message(Danger, MSG_DAN_0);
		return (1);
	}
	else if (argc >= 4)
	{
		ft_message(Danger, MSG_DAN_1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, handler);
	while (argv[2][i])
	{
		send += send_signal(pid, argv[2][i]);
		i++;
	}
	print_line(15);
	ft_printf("\n");
	ft_printf(GREEN"%d bits have been successfully sent.\n", send);
	ft_printf("%d bits have been successfully received.\n", g_received);
	return (0);
}

//   if (signal(SIGINT, catch_function) == SIG_ERR) {
//         fputs("An error occurred while setting a signal handler.\n", stderr);
//         return EXIT_FAILURE;
//     }
