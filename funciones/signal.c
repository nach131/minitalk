/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:57:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/27 17:44:57 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

//  sig_t	signal(int sig, sig_t func);

#include <stdio.h>
#include <signal.h>

int main(void)
{
	char s[1024];

	signal(SIGINT, SIG_IGN);    // Ignore SIGINT, caused by CTRL + C

	printf("Try hitting CTRL + C (^C)... (hit RETURN to exit)\n");

	// Wait for a line of input so the program doesn't just exit
	fgets(s, sizeof s, stdin);
}
