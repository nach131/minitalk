/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_bite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:52:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/12 13:34:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>
// int main(void)
// {
// 	char *str = "01111111";
// 	// char *str = "0000000110111101";

// 	static int	bite = 0;
// 	static unsigned char ch = 0;
// 	// static unsigned short ch = 0;

// 	int	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		ch = ch << 1;
// 		if (str[i] == '1')
// 		{
// 			// write(1, "1", 1);
// 			ch = ch | 1;
// 		}
// 		else
// 		{
// 			// write(1, "0", 1);
// 		}
// 		i++;
// 	}
// 	write(1, &ch, 1);
// }

void	ft_print_bits(unsigned char octet)
{
	int		i;
	char	bits;

	i = 7;
	while (i >= 0)
	{
		bits = ((octet >> i) & 1) + '0';
		// ft_printf(GREEN"%c", bits);
		write(1, &bits, 1);
		i--;
	}

}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i] != '\0')
		{
			ft_print_bits(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}
