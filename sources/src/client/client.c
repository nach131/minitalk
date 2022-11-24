/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/24 08:37:23 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

static void	send_signal(const int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_message(Warning, MSG_WAR_1);
		exit(EXIT_FAILURE);
	}
	usleep(300);
}

static void	char_to_byte(const int pid, char ch)
{
	int	bite;

	bite = 7;
	ft_printf(ORANGE"'%c' \u2911  "WHITE, ch);
	while (bite >= 0)
	{
		if (((ch >> bite) & 1) == 1)
		{
			ft_printf(CYAN"1");
			send_signal(pid, SIGUSR1);
		}
		else
		{
			ft_printf(CYAN"0");
			send_signal(pid, SIGUSR2);
		}
		bite--;
		usleep(300);
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

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
	while (argv[2][i])
	{
		char_to_byte(pid, argv[2][i]);
		i++;
	}
	return (0);
}
