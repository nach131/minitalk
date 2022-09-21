/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:34:51 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/21 22:44:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 /* ╔════════════════════════════════════════════════════════════════════════╗ */
 /* ║                 https://github.com/nach131/42Barcelona                 ║ */
 /* ╚════════════════════════════════════════════════════════════════════════╝ */

//  int	kill(pid_t pid, int sig);

#include <stdio.h>
#include <unistd.h>

#include <signal.h>

int main(void)
{
	int	pid = 0;

	printf("Introduce the PID: ");
	scanf("%d", &pid);

	kill(pid, SIGINT);
}

// kill -l

//   1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL
//  5) SIGTRAP      6) SIGABRT      7) SIGEMT       8) SIGFPE
//  9) SIGKILL     10) SIGBUS      11) SIGSEGV     12) SIGSYS
// 13) SIGPIPE     14) SIGALRM     15) SIGTERM     16) SIGURG
// 17) SIGSTOP     18) SIGTSTP     19) SIGCONT     20) SIGCHLD
// 21) SIGTTIN     22) SIGTTOU     23) SIGIO       24) SIGXCPU
// 25) SIGXFSZ     26) SIGVTALRM   27) SIGPROF     28) SIGWINCH
// 29) SIGINFO     30) SIGUSR1     31) SIGUSR2
