#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Proceso hijo
        execl("./ipc", "./ipc", "5", "X", NULL);
        perror("Error al ejecutar ipc");
        exit(EXIT_FAILURE);
    } 

    wait(NULL);  // Esperar a que termine el proceso hijo
    return 0;
}
