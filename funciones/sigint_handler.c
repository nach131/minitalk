/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:16:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/19 21:20:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

void sigint_handler(int signum)
{
	// The compiler is allowed to run:
	//
	//   signal(signum, SIG_DFL)
	//
	// when the handler is called. So we reset the handler here:
	signal(SIGINT, sigint_handler);

	(void)signum;   // Get rid of unused variable warning

	count++;                       // Undefined behavior
	printf(" Pulsado: %d\n", count);  // Undefined behavior

	if (count == 5) {
		printf("Exiting!\n");      // Undefined behavior
		exit(0);
	}
}

int main(void)
{
	signal(SIGINT, sigint_handler);

	printf("Try hitting ^C...\n");

	for (;;);  // Wait here forever
}

// Try hitting ^C...
// ^C Pulsado: 1
// ^C Pulsado: 2
// ^C Pulsado: 3
// ^C Pulsado: 4
// ^C Pulsado: 5
// Exiting!
