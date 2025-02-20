#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3, pid4;

    // Primer fork
    pid1 = fork();
    if (pid1 == 0) {
        printf("Soy el hijo 1 con PID: %d\n", getpid());
    } else {
        // Segundo fork
        pid2 = fork();
        if (pid2 == 0) {
            printf("Soy el hijo 2 con PID: %d\n", getpid());
        } else {
            // Tercer fork
            pid3 = fork();
            if (pid3 == 0) {
                printf("Soy el hijo 3 con PID: %d\n", getpid());
            } else {
                // Cuarto fork
                pid4 = fork();
                if (pid4 == 0) {
                    printf("Soy el hijo 4 con PID: %d\n", getpid());
                }
            }
        }
    }

    // Imprimir el PID del proceso actual
    printf("Proceso actual con PID: %d\n", getpid());
    return 0;
}
