/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:49:43 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/26 10:06:15 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <signal.h>

void	handle_sig_stp(int sig)
{
	printf("Stop not allowed\n");
}

int	main(int n, char *argv[])
{
	struct sigaction sa;
	sa.sa_handler = &handle_sig_stp;
	sa.sa_flags = SA_RESTART;
	// sigaction(SIGTSTP, &sa, NULL); // ctrl + z
	sigaction(SIGINT, &sa, NULL); // ctrl + c

	int	x;
	while (x != 25)
	{
		printf("Input number: ");
		scanf("%d", &x);
		printf("Result %d * 5 = %d\n", x, x * 5);
		if (x == 25)
			break;
	}
	return (0);
}
