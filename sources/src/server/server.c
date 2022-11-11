/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/11 09:58:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include "minitalk.h"
// #include <limits.h>
#include "../../libft/inc/libft.h"
#include <unistd.h>

// static void handler_server()
// {
// 	ft_message(Info, MSG_INF_1);
// }

static void ft_get_pid(void)
{
	int	pid; // SI NO LO USO QUITAR Y PONER EN FT_MESSAGE
	pid = getpid();

	if (!pid)
		ft_message(Danger, MSG_DAN_1);
	ft_putstr_fd(ORANGE" Pid: ", 1);
	// ft_printf("%i\n", getpid());
	ft_printf("%i\n", pid);
}

int	main(void)
{
	// struct sigaction sa;
	ft_get_pid();
	ft_process_bar();


	return(0);
}
