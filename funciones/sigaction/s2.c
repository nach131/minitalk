/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:49:24 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/10 21:45:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */


#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int num)
{
	write(STDOUT_FILENO, "No para\n", 8);
	if (num == 30)
		printf("SIGUSR1 n: %d\n", num);
	else if (num == 31)
		printf("SIGUSR2 n: %d\n", num);

}

void seghandle(int num)
{
	write(STDOUT_FILENO, "Seg Fault\n", 10);
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		perror("SIGEMPTYSET")
		//sigmeptyset() function initializes the signal set pointer by the parameter
		// declaration in signal.h == int  sigaddset(sigset_t *set, int signo);
		sa.sa_flags = SA_RESTART; // enamble functiosn to re-run if it was interrupted by handler

	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);

	while (1)
	{
		printf("%d Infinite LOOP\n", getpid());
		sleep(1);
	}
}
