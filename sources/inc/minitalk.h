/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 05:55:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/08 20:34:33 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
// # include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

# define ERROR_0 1 << 0
# define ERROR_1 1 << 1
# define ERROR_2 1 << 2
# define ERROR_3 1 << 3

// enum e_error_num {
// 	ERROR_4 = 1 << 4
// };

#define Red		"\033[0;31m"
#define Green	"\033[0;32m"
#define Yellow	"\033[0;33m"
#define Blue	"\033[0;34m"
#define Magenta	"\033[0;35m"
#define Cyan	"\033[0;36m"
#define White	"\033[0;37m"
#define Orange "\033[1;31m"


void	ft_error(unsigned char error);

#endif
