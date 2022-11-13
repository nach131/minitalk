/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respuesta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:52:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/13 22:06:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* Can't call standard string functions from signal hander. Write our own. */

int ltoa(unsigned long i, char *buf)
{
	char mybuf[20] = "0";
	char *mbp = mybuf;
	char *bp = buf;

	if (i == 0)
		*mbp++ = '0';
	else while (i > 0) {
		*mbp++ = '0' + (i % 10);
		i /= 10;
	}
	while (--mbp >= mybuf)
		*bp++ = *mbp;
	*bp = '\0';
	return bp - buf;
}


void handler(int sig, siginfo_t *si, void *uc)
{
	unsigned long pid = si->si_pid;
	char buf[20];
	int buflen;

	write(1, "Received signal ", 16);
	buflen = ltoa(sig, buf);
	write(1, buf, buflen);
	write(1, " from ", 6);
	buflen = ltoa(pid, buf);
	write(1, buf, buflen);
	write(1, "\n", 1);
}

int main()
{
	int pid = getpid();

	printf("%i\n", pid);

	struct sigaction sa = { .sa_sigaction = handler, .sa_flags = SA_SIGINFO };
	// struct sigaction oldsa;

	// sigaction(SIGINT, &sa, &oldsa);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);

	while (1)
	{
		sleep(10);
	}
}

// server
// kill -30 39389
// kill -31 39389

// client
// Received signal 30 from 71830
// Received signal 31 from 71830
