/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:47:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/23 12:47:30 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// sleep suspende al proceso llamador por la una cantidad de segundos
// indicada o hasta que se reciba una señal.

#include <unistd.h>

// unsigned int sleep(unsigned int seconds);


void ft_print(int n)
{
	write(1, &n, 1);
}

int main(void)
{

	int i = 0;

	while (i < 126)
	{
		if (i == 58)
			sleep(3);
		ft_print(i);
		// write(1, &i, 1);
		i++;
	}
}
