/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/12 12:26:11 by nmota-bu         ###   ########.fr       */
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

	if (sig == 30)
		ft_printf("1");
	else if (sig == 31)
		ft_printf("0");
	// ft_printf("\n");
}


// static void tokemo(int sig, siginfo_t *info, void *data)
// {
// 	// write(1, "\n", 1);
// 	(void)sig;
// 	(void)info;
// 	(void)data;


// 	if (info->si_signo == 30)
// 	{
// 		// ft_print_bits('0');
// 		ft_printf("1");

// 	}
// 	else if (info->si_signo == 31)
// 	{
// 		ft_printf("0");
// 		// ft_print_bits('1');
// 	}
// 	// printf(BLUE"NO HACE NADA\n");
// 	// printf(ORANGE"%s\n", data);
// 	// ft_printf(BLUE"si_signo %i\n", info->si_signo);
// 	// printf(RED"%li- %i", info->si_band, info->si_errno);
// 	ft_printf(WHITE"");
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
	struct sigaction sa;
	// sa.sa_flags = SA_RESTART;
	sa.sa_flags = SA_SIGINFO;
	// sa.sa_sigaction = tokemo;
	sa.sa_handler = handler;
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
		sleep(5);

	return(0);
}
