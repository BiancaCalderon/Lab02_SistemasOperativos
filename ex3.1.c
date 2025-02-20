#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double elapsed_time;

    start = clock(); // Inicia medición de tiempo

    // Tres ciclos for consecutivos
    for (long i = 0; i < 1000000; i++) {
        printf("Loop 1 - Iteration: %ld\n", i);
    }
    
    for (long i = 0; i < 1000000; i++) {
        printf("Loop 2 - Iteration: %ld\n", i);
    }

    for (long i = 0; i < 1000000; i++) {
        printf("Loop 3 - Iteration: %ld\n", i);
    }

    end = clock(); // Finaliza medición de tiempo

    // Calcula el tiempo transcurrido
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", elapsed_time);

    return 0;
}
