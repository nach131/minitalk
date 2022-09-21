/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniciate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:32:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/21 22:46:02 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	while (1)
		printf("%d Infinite LOOP\n", getpid());
}


// https://www.youtube.com/watch?v=qXP4F49K1XM&list=PLyLXXSiuhPPdDGWUm4QlctAq2UDvcOIcP
