/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/13 22:00:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"
// ESTO PARA DEBUG VS
#include <stdio.h>
// #include "../../inc/minitalk.h"
// #include "../../libft/inc/libft.h"

// #include <limits.h>

static void handler(int sig)
{

	static int bite = 0;
	static unsigned char ch = '\0';

	ch = ch << 1;
	if (sig == SIGUSR1)
		ch = ch | 1;
	else
	{
	}
	bite++;
	if (bite == 8)
	{
		ft_printf(GREEN"%c", ch);
		bite = 0;
		ch = '\0';
	}
}

// static void tokemo(int sig, siginfo_t *info, void *data)
// {

// 	(void)sig;
// 	(void)data;
// 	static int bite = 0;
// 	static unsigned char ch = '\0';

// 	ch = ch << 1;
// 	if (info->si_signo == SIGUSR1)
// 		ch = ch | 1;
// 	else
// 	{
// 	}
// 	bite++;
// 	if (bite == 8)
// 	{
// 		ft_printf(GREEN"%c", ch);
// 		bite = 0;
// 		ch = '\0';
// 	}
// }

static void ft_get_pid(void)
{
	int	pid; // SI NO LO USO QUITAR Y PONER EN FT_MESSAGE
	pid = getpid();

	if (!pid)
		ft_message(Danger, MSG_DAN_1);
	ft_printf(ORANGE" Pid: %i\n"WHITE, pid);
}

static void init()
{
	struct sigaction sa = {
		.sa_handler = handler,
		.sa_flags = SA_RESTART
	};

	// sa.sa_flags = SA_RESTART;
	// sa.sa_sigaction = tokemo;
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
		sleep(10);
	}
	return(0);
}
