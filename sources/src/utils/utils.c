/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/08 20:37:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"
#include "../../libft/inc/libft.h"


void	ft_error(unsigned char error)
{
	if (error & ERROR_0)
		ft_putstr_fd(Red"Error 0: Arguments missing \n"White, 1);
	if (error & ERROR_1)
		ft_putstr_fd(Red"Error 1: Could not generate the PID\n"White, 1);
	// printf("%s", ERR_MS1);
	if (error & ERROR_2)
		ft_putstr_fd(Red"Error 2: Not defined yet\n"White, 1);
	if (error & ERROR_3)
		ft_putstr_fd(Red"Error 3: Not defined yet\n"White, 1);
}
