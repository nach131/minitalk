/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>

int	main(void)

{

	int i;
	char str[] = "42 Barcelona";
	i = -1;

//	while(str[i] != '\0' && ++i > -2)
	while(str[++i])
	{
		write(1, &str[i], 1);
	}
}
