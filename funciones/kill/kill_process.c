/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:34:51 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/26 21:33:39 by nmota-bu         ###   ########.fr       */
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


	// SIGALRM: generada cuando el timer asociado a la función alarm expira. También cuando el timer de intervalo es configurado (setitimer)
	// SIGCHLD: Cuando un proceso termina o para, el proceso envía esta señal a su padre.
	// 		Por defecto esta señal es ignorada. Normalmente el proceso padre invoca la función wait para obtener el estatus
	// 		de término del proceso hijo. Se evita así la creación de procesos "zombies".
	// SIGCONT: es enviada para reanudar un proceso que ha sido parado (suspendido) con SIGSTOP.
	// SIGINT: generada con DELETE o Control-C
	// SIGKILL: Permite terminar un proceso.
	// SIGTSTP: generada cuando presionamos Control-Z. Puede ser ignorada.
	// SIGSTOP: similar a SIGTSTP pero no puede ser ignorada o capturada.
	// SIGUSR1: Es una señal definida por el usuario para ser usada en programas de aplicación.
	// SIGUSR2: Otra como la anterior.
