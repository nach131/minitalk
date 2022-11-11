/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniciate_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:32:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/10 14:11:23 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// getpid, getppid -- get parent or calling process identification
// getpid() returns the process ID of the calling process.  The ID is guaranteed to be unique and is useful for
//     constructing temporary file names.


#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	handler_put(int sig)
{
	printf("Signal n: %d\n", sig);

}

int	main(void)
{
	signal(SIGUSR1, &handler_put);

	while (1)
	{
		printf("%d Infinite LOOP\n", getpid());
		sleep(2);
	}
}

// kill -SIGUSR1 <num pid> // ejecuta handler_put
