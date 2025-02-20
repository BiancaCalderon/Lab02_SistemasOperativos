#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); // Crear un nuevo proceso

    if (pid < 0) {
        // Error al crear el proceso
        perror("Error en fork");
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        printf("Soy el proceso hijo con PID %d. Terminaré ahora.\n", getpid());
    } else {
        // Proceso padre
        printf("Soy el proceso padre con PID %d. Entrando en un ciclo infinito...\n", getpid());
        while (1) {
            // Bucle infinito en el proceso padre
        }
    }

    return 0;
}
