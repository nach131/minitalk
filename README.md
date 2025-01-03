<h1 align="center">
  <img  width="120" alt="42logo"  src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">
  
	minitalk
</h1>

 <p align="center">
<img alt="total-views" src="https://img.shields.io/badge/views-1-blue">
<img alt="total-clone" src="https://img.shields.io/badge/clone-46-blue">
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/nach131/minitalk">
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/nach131/minitalk">
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/nach131/minitalk">
<img alt="license-MIT" src="https://img.shields.io/badge/license-MIT-blue">
</p>

<span align="center">

![visitors](https://visitor-badge.glitch.me/badge?page_id=nach131.minitalk&left_color=green&right_color=blue)

![minitalk](https://github.com/nach131/42Barcelona/blob/main/images/125.png)

![gif](minitalk.gif)
### minitalk
![mapa](minitalk.png)
### minitalk bonus
![mapa](minitalk_bonus.png)

</span>

 Funciones permitidas

 `sigemptyset` , `sigaddset` , `sigaction` , `kill` , `getpid` , `malloc` , `free` , `pause` , `sleep` , `usleep` , `exit`


# Procesos en Unix

Proceso es la instancia de un programa, se pueden crear **n** cantidades de instancias según ejecuciones del programa.

Todos los procesos poseen 4 atributos para poder gestionarlos.

| 	| 	|
| --- | --- |
| PID | ***(Process ID)*** Identificador único para cada proceso. conformado por 5 numeros enteros |
| PPID | ***(Parent Process ID)*** En Unix, cada proceso es creado, por un proceso, este seria el proceso padre.
| TTY | Terminal a la que esta asociada el proceso, no todos los procesos son creados en terminal, puede haber procesos sin TTY. |
| UID | ***(User ID)*** Usuario al que pertenece el proceso.

Listar todos los procesos.

	ps

Listar los procesos con el PPID

	ps -f

## Finalizar un proceso

Para finalizar un proceso tenemos dos formas, pulsando **ctrl + C** o localizando el PID

	kill -9 <PID>

### [getped()](https://github.com/nach131/minitalk/blob/main/funciones/kill/iniciate.c)

### [kill process](https://github.com/nach131/minitalk/blob/main/funciones/kill/kill_process.c)

# Signals

Los signals son la método por el cual podemos comunicar procesos entre si (las señales).
Para conocer los signals disponibles en el sistema

	kill -l

Cada señal tiene un numero entero que la representa, y un nombre.
|	|	|	|	|
| -- | -- | -- | -- |
| 1) SIGHUP   |   2) SIGINT    |  3) SIGQUIT    |   4) SIGILL |
| 5) SIGTRAP  |   6) SIGABRT   |  7) SIGEMT     |   8) SIGFPE |
| 9) SIGKILL  |  10) SIGBUS    | 11) SIGSEGV    |  12) SIGSYS |
| 13) SIGPIPE |   14) SIGALRM  |  15) SIGTERM   |   16) SIGURG |
| 17) SIGSTOP |   18) SIGTSTP  |  19) SIGCONT   |   20) SIGCHLD |
| 21) SIGTTIN |   22) SIGTTOU  |  23) SIGIO     |   24) SIGXCPU |
| 25) SIGXFSZ |   26) SIGVTALRM|  27) SIGPROF   |   28) SIGWINCH |
| 29) SIGINFO |   30) SIGUSR1  |  31) SIGUSR2 |  |

|	Numero | Nombre| Descripción|
| -- | -- | -- |
| 1 | SIGHUP | Cuelgue del terminal o proceso terminado |
| 2 | SIGINT | Emitido si el usuario interrumpe el proceso ***Ctrl + C***|
| 3 | SIGQUIT | Emitido si el usuario envía señal de salida ***Ctrl + D***| Puntero
| 8 | SIGFPE | Emitido si se intenta operación matemática prohibida |
| 9 | SIGKILL | Permite cerrar un proceso y no realiza ninguna operación de limpieza |
| 14 | SIGALRM | Emitido cuando el timer asociado a la función alarm expira. También cuando el timer de intervalo es configurado (setitimer) |
| 15 | SIGTERM | Señal de terminación de software (enviada por kill por defecto) |
| 17 | SIGSTOP | similar a SIGTSTP pero no puede ser ignorada o capturada.|
| 18 | SIGTSTP | generada cuando presionamos ***Control + Z***. Puede ser ignorada.|
| 19 | SIGCONT | Emitido para reanudar un proceso que ha sido parado (suspendido) con SIGSTOP |
| 20 | SIGCHLD | Cuando un proceso termina o para, el proceso envía esta señal a su padre. Por defecto esta señal es ignorada. Normalmente el proceso padre invoca la función wait para obtener el estatus de término del proceso hijo. Se evita así la creación de procesos "zombies" |
| 29 | SIGINFO | Es una señal 1 definida por el usuario|
| 30 | SIGUSR1 | Es una señal 1 definida por el usuario|
| 31 | SIGUSR2 | Es una señal 2 definida por el usuario|

# [Signal()](https://github.com/nach131/minitalk/blob/main/funciones/signal.c)
 ```c
	 sig_t	signal(int sig, sig_t func);
```

Genera una señal en una variedad de eventos externos, se puede configurar para que se interrumpa y continuar donde se dejo.

 # [sigaction()](https://github.com/nach131/minitalk/tree/main/funciones/sigaction)
```c
 int	sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
```
Permite que el proceso de llamada examine o especifique la acción que se llevará a cabo al recibir una señal específica.

El argumento sig especifica la señal y se le puede asignar cualquiera de las señales especificadas en signal.h excepto SIGKILL y SIGSTOP.

>Si el argumento ***act*** no es ***NULL***, apunta a una estructura que especifica la nueva acción de entrega de **signal**
Si el argumento ***oact*** no es ***NULL*** apunta a una estructura donde la acción previamente asociada con **signal** almacenara el retorno de **sigaction**.
>

```c
struct sigaction {
    void      (*sa_handler)(int);	 // puntero a una función
    void      (*sa_sigaction)(int, siginfo_t *, void *); // puntero a una función
    sigset_t  sa_mask;     		// máscara de señal para aplicar */
    int       sa_flags;        		// Signal a continuación*/
    void      (*sa_restorer)(void); 	// opsoleto NO USAR.
    }
```
`sa_mask` máscara  de  señales  que  deberían  bloquearse durante la ejecución del manejador de señal. Además, la señal que lance el manejador será bloqueada.

`sa_flag` máscara  de  señales  que  deberían  bloquearse durante la ejecución de sigaction (`función`)

Estructuras dentro de sigaction

CUIDADO : en algunas arquitecturas se utiliza union para `sa_handler` y `sa_sigation`
```c
  union __sigaction_u {
    void    (*__sa_handler)(int);
    void    (*__sa_sigaction)(int, siginfo_t *, void *);
    };
```

`sa_handler` Puntero de la función de captura 

`sa_sigaction` Puntero de la función de captura 

El parámetro `siginfo_t` para sa_sigaction es una estructura con los siguientes elementos

```c
siginfo_t {
	int      si_signo;  /* Número de señal */
	int      si_errno;  /* Un valor errno */
	int      si_code;   /* Código de señal */
	pid_t    si_pid;    /* ID del proceso emisor */
	uid_t    si_uid;    /* ID del usuario real del proceso emisor */
	int      si_status; /* Valor de salida o señal */
	clock_t  si_utime;  /* Tiempo de usuario consumido */
	clock_t  si_stime;  /* Tiempo de sistema consumido */
	sigval_t si_value;  /* Valor de señal */
	int      si_int;    /* señal POSIX.1b */
	void *   si_ptr;    /* señal POSIX.1b */
	void *   si_addr;   /* Dirección de memoria que ha producido el fallo */
	int      si_band;   /* Evento de conjunto */
	int      si_fd;     /* Descriptor de fichero */
}
```