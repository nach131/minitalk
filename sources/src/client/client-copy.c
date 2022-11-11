/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/09 21:07:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include "minitalk.h"


int	main(int argc, char **argv)
{
	(void)argv;

	if (argc != 3)
	{
		ft_message(Danger, MSG_DAN_0);
		return(1);
	}

	ft_message(Danger, MSG_DAN_1);
	ft_message(Warning, MSG_WAR_1);
	ft_message(Info, MSG_INF_1);
	ft_message(Success, MSG_SUC_1);


	return(0);
}


