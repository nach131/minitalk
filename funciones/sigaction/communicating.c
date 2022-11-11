/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:49:24 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/11 12:06:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// https://www.youtube.com/watch?v=ShWkfAyuuWw

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

int x = 0;

void mult(void)
{
	write(1, "3 x 5 = ", 8);
}

void handler_sigurs1(int signum)
{
	if (x == 0)
	{
		write(1, "\nEscribe el resultado\n", 22);
		mult();
	}
}

int	main(int argc, char *argv[])
{
	int pid = fork(); // para realizar procersos hijos
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		// Child process
		sleep(2);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handler_sigurs1;
		sigaction(SIGUSR1, &sa, NULL);

		// Parent process
		// printf("3 x 5 = ");
		mult();
		scanf("%d", &x);
		if (x == 15)
			printf("Muy bien\n");
		else
			printf("Mal\n");
		wait(NULL);
	}

	return (0);
}
