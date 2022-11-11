/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/11 20:15:38 by nmota-bu         ###   ########.fr       */
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

// static void handler_sigurs1()
// {
// 	ft_message(Info, MSG_INF_1);
// }

// void (*)(int, struct __siginfo *, void *)
static void tokemo(int sig, siginfo_t *info, void *data)
{
	write(1, "\n", 1);
	(void)sig;
	if (info->si_signo == 30)
	{
		ft_print_bits('0');
	}
	else if (info->si_signo == 31)
	{
		ft_print_bits('1');
	}
	(void)info;
	(void)data;
	printf(ORANGE"%s\n", data);
	ft_printf(BLUE"si_signo %i\n", info->si_signo);
	printf(RED"%li- %i", info->si_band, info->si_errno);
	ft_printf(WHITE"");


}

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
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = tokemo;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{

	ft_get_pid();
	init();
	ft_process_bar();

	return(0);
}
