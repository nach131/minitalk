<h1 align="center">
  <img  width="120" alt="42logo"  src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">
  
	minitalk
</h1>
 <p align="center">
<!-- <img alt="total-views" src="https://img.shields.io/badge/views-46-blue"> -->
<!-- <img alt="total-clone" src="https://img.shields.io/badge/clone-172-blue"> -->
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/nach131/minitalk">
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/nach131/minitalk">
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/nach131/minitalk">
<img alt="license-MIT" src="https://img.shields.io/badge/license-MIT-blue">
</p>

<h1 align="center">

<!-- ![mapa](minitalk.png) -->
</h1>

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



# Signal()

Genera una señal en una variedad de eventos externos, se puede configurar para que se interrumpa y continuar donde se dejo.

 sigemptyset,  sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit

 # sigaction()

estructuras dentro de sigaction

|   |   |
|---|---|
|**sa_handler** | Puntero de la función de captura |
| **sa_mask**  | Adicional asignación del bloqueo durante la ejecución de la función de captura |
| **sa_flag**  | Aviso especial durante comportamiento de signal  |
| **sa_sigaction**  | Puntero de la función de captura  |