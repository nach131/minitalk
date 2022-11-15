/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/15 22:49:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

static void handler(int sig)
{

	static int bite = 0;
	static unsigned char ch = '\0';

	ch <<= 1;
	if (sig == SIGUSR1)
		ch |= 1;
	bite++;
	if (bite == 8)
	{
		if ((int)ch <= 126)
			ft_printf(GREEN"%c", ch);
		else if ((int)ch >= 127)
			ft_printf("%c", ch);
		bite = 0;
		ch = '\0';
	}
}

// static void tokemo(int sig, siginfo_t *info, void *data)
// {

// 	// (void)sig;
// 	(void)data;
// 	(void)info;
// 	static int bite;
// 	static unsigned char ch;

// 	// if (info->si_signo == SIGUSR1)

// 	if (sig == SIGUSR1)
// 		ch |= 1;
// 	bite++;
// 	if (bite == 8)
// 	{
// 		// ft_printf(GREEN"%c", ch);
// 		write(1, &ch, 1);
// 		bite = 0;
// 	}
// 	ch <<= 1;
// }

static void ft_get_pid(void)
{
	int	pid;
	pid = getpid();

	if (!pid)
		ft_message(Danger, MSG_DAN_1);
	ft_printf(ORANGE" Pid: %i\n"WHITE, pid);
}

static void init()
{
	struct sigaction sa = {
		.sa_handler = handler,
		// .sa_sigaction = tokemo,
		.sa_flags = SA_RESTART
	};

	// sa.sa_flags = SA_RESTART;
	// sa.sa_mask = SA_RESTART | SIGINT | SIGQUIT | SIGTERM;
	// sa.sa_mask = SIGINT;
	// sa.sa_handler = handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_get_pid();
	init();
	// ft_process_bar();
	while (1)
	{
		sleep(200);
	}
	return(0);
}
