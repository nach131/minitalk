/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 05:55:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/09 16:01:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/colors.h"
# include "../libft/inc/ft_printf.h"

# define ERROR_0 1
# define ERROR_1 2
# define ERROR_2 4
# define ERROR_3 8

// enum e_error_num {
// 	ERROR_4 = 1 << 4
// };

// enum e_error_num {
// 	ERROR_4 = 0
// };

void	ft_error(unsigned char error);
void	ft_print_bits(unsigned char octet);

#endif
