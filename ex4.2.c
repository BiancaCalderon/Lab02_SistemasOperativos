#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int main() {
    pid_t pid = fork(); // Crear un nuevo proceso

    if (pid < 0) {
        // Error al crear el proceso
        perror("Error en fork");
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        int count_limit = 4000000;
        clock_t start_time = clock();
        
        for (int i = 1; i <= count_limit; i++) {
            printf("%d\n", i);
            // Esperamos un poco entre cada número para controlar el tiempo
            usleep(1000); // 1000 microsegundos (1 ms)
        }

        clock_t end_time = clock();
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("El conteo tomó %.2f segundos.\n", time_taken);
    } else {
        // Proceso padre
        printf("Soy el proceso padre con PID %d. Entrando en un ciclo infinito...\n", getpid());
        while (1) {
            // Bucle infinito en el proceso padre
        }
    }

    return 0;
}




