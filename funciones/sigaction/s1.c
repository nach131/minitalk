/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:24:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/10 20:41:15 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <signal.h>

// using namespace std;

// void	handler(int signum)
// {
// 	if (signum == SIGINT)
// 	{
// 		count << " CONTROL SIGNAL IS PRESSED!";
// 	}
// }

// int	main()
// {
// 	struct sigaction sa;
// 	sa.sa_handler = handler;

// 	while (1)
// 	{
// 		cerr << "/";
// 		usleep(1000000);
// 		if (sigaction(SIGINT, &sa, NULL) == 1)
// 			perror("SIGACTION");
// 	}
// 	return(0);
// }

#include <signal.h>


static void handler(int signum)
{
	if (signum == SIGINT)
		printf("SIGINT\n");
	else if (signum == SIGUSR1)
		printf("SIGUSR1\n");
	else if (signum == SIGUSR2)
		printf("SIGUSR2\n");

	/* Take appropriate actions for signal delivery */
}


int main()
{
	struct sigaction sa;

	sa.sa_handler = handler;
	// sigemptyset(&sa.sa_mask);
	sa.sa_flags = SIGINT;
	// sa.sa_flags = SA_RESTART; // Restart functions if interrupted by handler

	// sigaction(SIGUSR1, &sa, NULL);


	while (1)
	{

		if (sigaction(SIGINT, &sa, NULL) == -1)
			printf("error");
		/* Handle error */;
		printf("%d Infinite LOOP\n", getpid());
		sleep(2);
	}

	/* Further code */
}
