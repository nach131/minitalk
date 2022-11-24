/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/24 08:34:12 by nmota-bu         ###   ########.fr       */
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

static void	send_signal(const int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_message(Warning, MSG_WAR_1);
		exit(EXIT_FAILURE);
	}
	usleep(300);
}

static int	char_to_byte(const int pid, char ch, int bite)
{
	int	send;

	send = 0;
	ft_printf(ORANGE"'%c' \u2911  "WHITE, ch);
	while (bite >= 0)
	{
		if (((ch >> bite) & 1) == 1)
		{
			ft_printf(CYAN"1");
			send_signal(pid, SIGUSR1);
			send++;
		}
		else
		{
			ft_printf(CYAN"0");
			send_signal(pid, SIGUSR2);
			send++;
		}
		bite--;
		usleep(300);
	}
	ft_printf("\n");
	return (send);
}

static void	print_response(int send)
{
	ft_putuni(16, FBLOCK, YELLOW);
	ft_printf("\n");
	ft_printf(GREEN"%d bits have been successfully sent.\n", send);
	ft_printf("%d bits have been successfully received.\n", g_received);
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
	i = -1;
	signal(SIGUSR1, handler);
	while (argv[2][++i])
		send += char_to_byte(pid, argv[2][i], 7);
	print_response(send);
	return (0);
}

//   if (signal(SIGINT, catch_function) == SIG_ERR) {
//         fputs("An error occurred while setting a signal handler.\n", stderr);
//         return EXIT_FAILURE;
//     }
