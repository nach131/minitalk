/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/23 23:14:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

// static void	ft_process_bar(void)
// {
// 	int i = 0;
// 	char *arrows[5];

// 	arrows[0] = "\u25aa";
// 	arrows[1] = "\u25fc";
// 	arrows[2] = "\u2588";
// 	arrows[3] = "\u25fc";
// 	arrows[4] = "\u25aa";

// 	while (1)
// 	{
// 		ft_printf(RED"%s", arrows[i]);
// 		i++;
// 		if (i > 4)
// 			i = 0;
// 		usleep(200000);
// 		write(1, "\b", 1);
// 	}
// }

static void	handler(int sig)
{
	static int				bite = 0;
	static unsigned char	ch = '\0';

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

static void	ft_get_pid(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		ft_message(Danger, MSG_DAN_1);
	ft_printf(ORANGE" Pid: %i\n"WHITE, pid);
}

static void	init(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_get_pid();
	init();
	while (1)
		sleep(300);
	return (0);
}
