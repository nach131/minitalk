/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:24:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/26 10:58:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <signal.h>

using namespace std;

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		count << " CONTROL SIGNAL IS PRESSED!";
	}
}

int	main()
{
	struct sigaction sa;
	sa.sa_handler = handler;

	while (1)
	{
		cerr << "/";
		usleep(1000000);
		if (sigaction(SIGINT, &sa, NULL) == 1)
			perror("SIGACTION");
	}
	return(0);
}
