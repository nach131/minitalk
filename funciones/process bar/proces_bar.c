/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:29:13 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/10 14:49:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// C program to create loading bar
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <unistd.h>

// Function to creating loading bar
void loadingBar()
{
	// 0 - black background,
	// A - Green Foreground
	system("color 0A");

	// Initialize char for printing
	// loading bar
	char a = 45; 
	char b = 46;

	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t\t");
	printf("waiting message...\n\n");
	printf("\t\t\t\t\t");

	// Print initial loading bar
	for (int i = 0; i < 26; i++)
		printf("%c", a);

	// Set the cursor again starting
	// point of loading bar
	printf("\r");
	printf("\t\t\t\t\t");

	// Print loading bar progress
	for (int i = 0; i < 26; i++) {
		printf("%c", b);

		// Sleep for 1 second
		sleep(1);
	}
}

// Driver Code
int main()
{
	// Function Call
	loadingBar();
	return 0;
}

