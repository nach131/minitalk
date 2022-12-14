/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniciate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:32:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/10 13:56:19 by nmota-bu         ###   ########.fr       */
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

int	main(void)
{
	while (1)
	{
		printf("%d Infinite LOOP\n", getpid());
		sleep(1);
	}
}


// https://www.youtube.com/watch?v=qXP4F49K1XM&list=PLyLXXSiuhPPdDGWUm4QlctAq2UDvcOIcP
