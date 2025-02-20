#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Capturar el tiempo antes de los ciclos
    start = clock();

    // Ejecutar tres ciclos de un millón de iteraciones cada uno
    for (int i = 0; i < 1000000; i++);
    for (int i = 0; i < 1000000; i++);
    for (int i = 0; i < 1000000; i++);

    // Capturar el tiempo después de los ciclos
    end = clock();

    // Calcular el tiempo transcurrido en segundos
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Mostrar el tiempo transcurrido
    printf("Tiempo transcurrido: %f segundos\n", cpu_time_used);

    return 0;
}