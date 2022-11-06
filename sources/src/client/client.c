/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/06 13:07:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include "minitalk.h"
// #include "../../inc/minitalk.h"

void	ft_error(unsigned char error)
{
	if (error & ERROR_0)
		printf("Error 0\n");
	if (error & ERROR_1)
		printf("Error 1\n");
	if (error & ERROR_2)
		printf("Error 2\n");
	if (error & ERROR_3)
		printf("Error 3\n");

}

int	main(void)
{
	ft_printf("Tomate\n");
	ft_error(ERROR_1 | ERROR_3 | ERROR_0);

	return(0);
}


// gcc client.c ../../minitalk ../../libft/libft.a
