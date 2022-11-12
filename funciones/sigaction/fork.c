/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:20:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/12 21:00:04 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void hola()
{
	printf("Hola\n");
}


int	ft_process_bar(void)
{
	int pid = fork();

	struct sigaction sa;
	// sa.sa_flags = SA_RESTART;
	sa.sa_handler = &hola;
	sigaction(SIGTSTP, &sa, NULL);

	char arrows[6][12] = {
"(-o--------)" ,
"(-----o----)",
"(---------o)",
"(--------o-)",
"(---o------)",
"(o---------)" };

	int		i;
	int		j;

	i = 0;
	while (1)
	{
		write(1, &arrows[i], 12);
		i++;
		if (i > 5)
			i = 0;
		usleep(200000);
		j = 0;
		while (j < 15)
		{
			write(1, "\b", 1);
			j++;
		}
	}
	return(pid);
}


int	main(void)
{
	int pid = ft_process_bar();

	while (1)
	{
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			kill(pid, SIGTSTP);
		}
		hola();
		// kill(getppid(), SIGCONT);
	}
}


// SIGTSTP
// SIGCONT
