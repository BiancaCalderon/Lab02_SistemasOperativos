#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    clock_t start, end;
    double elapsed_time;
    pid_t pid_hijo, pid_nieto, pid_bisnieto;

    start = clock(); // Medir tiempo antes del fork

    pid_hijo = fork();

    if (pid_hijo == 0) { // Proceso hijo
        pid_nieto = fork();

        if (pid_nieto == 0) { // Proceso nieto
            pid_bisnieto = fork();

            if (pid_bisnieto == 0) { // Proceso bisnieto
                for (long i = 0; i < 1000000; i++) {
                    printf("Bisnieto - Iteration: %ld\n", i);
                }
            } else { // Proceso nieto
                wait(NULL); // Espera a bisnieto
                for (long i = 0; i < 1000000; i++) {
                    printf("Nieto - Iteration: %ld\n", i);
                }
            }
        } else { // Proceso hijo
            wait(NULL); // Espera a nieto
            for (long i = 0; i < 1000000; i++) {
                printf("Hijo - Iteration: %ld\n", i);
            }
        }
    } else { // Proceso padre
        wait(NULL); // Espera a hijo
        end = clock(); // Medir tiempo al final

        // Calcula el tiempo transcurrido
        elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecución: %f segundos\n", elapsed_time);
    }

    return 0;
}
