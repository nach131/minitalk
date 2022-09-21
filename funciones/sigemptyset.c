/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigemptyset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:41:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/21 16:41:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// These functions manipulate signal sets, stored in a sigset_t.
// Either sigemptyset() or sigfillset() must be
// called for every object of type sigset_t before any other use of the object.

// The sigemptyset() function initializes a signal set to be empty.
// int	sigemptyset(sigset_t *set);

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void print( sigset_t set, int signo )
  {

    printf( "Set %8.8lx. Signal %d is ", set, signo );
    if( sigismember( &set, signo ) )
      printf( "a member.\n" );
    else
      printf( "not a member.\n" );
  }

int main( void )
  {
    sigset_t set;

    sigemptyset( &set );
    print( set, SIGINT );

    sigfillset( &set );
    print( set, SIGINT );

    sigdelset( &set, SIGINT );
    print( set, SIGINT );

    sigaddset( &set, SIGINT );
    print( set, SIGINT );
    return EXIT_SUCCESS;
  }


// Set 00000000. Signal 2 is not a member.
// Set ffffffff. Signal 2 is a member.
// Set fffffffd. Signal 2 is not a member.
// Set ffffffff. Signal 2 is a member.
