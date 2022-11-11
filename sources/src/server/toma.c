/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toma.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/11 14:46:11 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// #include "minitalk.h"
// ESTO PARA DEBUG VS
#include "../../inc/minitalk.h"
#include "../../libft/inc/libft.h"

// #include <limits.h>

// static void handler_sigurs1()
// {
// 	ft_message(Info, MSG_INF_1);
// }

// void (*)(int, struct __siginfo *, void *)
static void tokemo(int sig, siginfo_t *info, void *data)
{
	write(1, "\n", 1);
	// ft_printf("%i\n", sig);
	// ft_printf("%s\n", data);
	ft_printf("%i\n", info->si_signo);
}

static void ft_get_pid(void)
{
	int	pid; // SI NO LO USO QUITAR Y PONER EN FT_MESSAGE
	pid = getpid();

	if (!pid)
		ft_message(Danger, MSG_DAN_1);
	ft_printf(ORANGE" Pid: %i\n"WHITE, pid);
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_RESTART;
	// sa.sa_flags = SA_SIGINFO;
	// sa.sa_handler = &handler_sigurs1;
	sa.sa_sigaction = tokemo;
	sigaction(SIGUSR1, &sa, NULL);

	ft_get_pid();
	ft_process_bar();

	return(0);
}
