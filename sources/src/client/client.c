/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/15 19:35:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minitalk.h"

static void	send_signal(const int pid, char ch)
{
	int	i;

	i = 7;
	ft_printf(ORANGE"'%c' \u2911  "WHITE, ch);
	while (i >= 0)
	{
		if (((ch >> i) & 1) == 1)
			{
				ft_printf(CYAN"1");
				kill(pid, SIGUSR1);
			}
			else
			{
				ft_printf(CYAN"0");
				kill(pid, SIGUSR2);
			}
		i--;
			usleep(200); // AUMENTAR SI SE PIERDEN BITE
	}
	ft_printf("\n");
}

// static void	print_bite(char ch, int bite)
// {

// 	ft_printf("\t%i", ch);
// 	// (void)bite;
// 	if ((int)ch <= 126)
// 		// ft_printf(CYAN"%i", bite);
// 		ft_printf(RED"@@", bite);
// 	else if ((int)ch >= 127)
// 		write(1, "@@@@", 4);
// 	// ft_printf(RED"%i", bite);
// }

// static void	send_signal(const int pid, char ch)
// {
// 	int	i;

// 	i = 8;

// 	ft_printf(ORANGE"'%c' \u2911  "WHITE, ch);

// 	while (i >= 0)
// 	{
// 		if (((ch >> i) & 1) == 1)
// 			{
// 			// ft_printf(CYAN"1");
// 			print_bite(ch, 1);
// 				kill(pid, SIGUSR1);
// 			}
// 			else
// 			{
// 			print_bite(ch, 0);
// 			// ft_printf(CYAN"0");
// 				kill(pid, SIGUSR2);
// 			}
// 		i--;
// 			usleep(200); // AUMENTAR SI SE PIERDEN BITE
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char **argv)
{
	int	pid;
	int i;

	if (argc <= 2)
	{
		ft_message(Danger, MSG_DAN_0);
		return(1);
	}
	else if (argc >= 4)
	{
		ft_message(Danger, MSG_DAN_1);
		return(1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}

	return(0);
}

