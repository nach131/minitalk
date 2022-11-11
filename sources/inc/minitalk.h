/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 05:55:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/11 09:55:58 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/colors.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/error.h"

// # define ERROR_0 1
// # define ERROR_1 2
// # define ERROR_2 4
// # define ERROR_3 8

// enum e_error_num {
// 	ERROR_4 = 1 << 4
// };

# define MSG_DAN_0 "Error 0: Arguments missing "
# define MSG_DAN_1 "Error 1: Could not generate the PID"
# define MSG_WAR_1 "Warning message 1"
# define MSG_INF_1 "Info message 1"
# define MSG_SUC_1 "Success message 1"

// typedef enum ERRORS
// {
// 	Danger,
// 	Warning,
// 	Success,
// }			ERR;

void	ft_print_bits(unsigned char octet);
void	ft_process_bar(void);

#endif
