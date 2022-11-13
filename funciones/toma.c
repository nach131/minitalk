/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include"../sources/libft/inc/libft.h"

int	main(void)
{
	int c;
	printf("Escribe un numero de caracter para comprobar si es imprimible\n");
	scanf("%d", &c);
	printf("el caracter '%c': %d\n", (char)c, ft_isprint(c));
}
