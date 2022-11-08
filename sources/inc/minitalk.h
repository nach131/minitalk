/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 05:55:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/08 09:38:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# include <signal.h>
// # include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

#define ERROR_0 1 << 0
#define ERROR_1 1 << 1
#define ERROR_2 1 << 2
#define ERROR_3 1 << 3

#define ERR_MS0	"Error 0\n"
#define ERR_MS1	"Error 1\n"
#define ERR_MS2	"Error 2\n"
#define ERR_MS3	"Error 3\n"

void	ft_error(unsigned char error);

#endif
