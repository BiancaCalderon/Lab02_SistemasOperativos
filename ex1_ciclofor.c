#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    for (int i = 0; i < 4; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Soy el hijo %d con PID: %d\n", i + 1, getpid());
            break; // Salir del ciclo para que el hijo no cree más hijos
        }
    }

    // Imprimir el PID del proceso actual
    printf("Proceso actual con PID: %d\n", getpid());
    return 0;
}
