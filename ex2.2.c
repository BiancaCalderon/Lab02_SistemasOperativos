#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    clock_t start, end;
    pid_t pid_hijo, pid_nieto, pid_bisnieto;
    
    // Capturar el tiempo antes del primer fork
    start = clock();
    
    pid_hijo = fork();
    
    if (pid_hijo == 0) { // Proceso hijo
        pid_nieto = fork();
        
        if (pid_nieto == 0) { // Proceso nieto
            pid_bisnieto = fork();
            
            if (pid_bisnieto == 0) { // Proceso bisnieto
                for (int i = 0; i < 1000000; i++);
            } else { // Proceso nieto espera al bisnieto
                wait(NULL);
                for (int i = 0; i < 1000000; i++);
            }
        } else { // Proceso hijo espera al nieto
            wait(NULL);
            for (int i = 0; i < 1000000; i++);
        }
    } else { // Proceso padre espera al hijo
        wait(NULL);
        
        // Capturar el tiempo después de que termine el hijo
        end = clock();
        
        // Calcular el tiempo transcurrido en segundos
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // Mostrar el tiempo transcurrido
        printf("Tiempo transcurrido: %f segundos\n", cpu_time_used);
    }
    
    return 0;
}