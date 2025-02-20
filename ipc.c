#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define SHM_NAME "/shared_mem_ipc"
#define MEM_SIZE 128

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <número> <carácter>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);   // Número de iteraciones
    char x = argv[2][0];     // Carácter a escribir en memoria compartida

    int shm_fd;
    char *shm_ptr;

    // Crear y configurar la memoria compartida
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Error al abrir la memoria compartida");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, MEM_SIZE) == -1) {
        perror("Error al ajustar tamaño de memoria compartida");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    shm_ptr = mmap(0, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("Error en mmap");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    // Inicializar memoria con 'b'
    memset(shm_ptr, 'b', MEM_SIZE - 1);
    shm_ptr[MEM_SIZE - 1] = '\0';

    printf("Memoria compartida antes: %s\n", shm_ptr);
    
    sleep(1); // Esperar antes de modificar

    for (int i = MEM_SIZE / 2; i < MEM_SIZE - 1; i++) {
        shm_ptr[i] = x;  // Modificar la segunda mitad de la memoria
    }

    printf("Memoria compartida después: %s\n", shm_ptr);

    // Liberar memoria compartida
    munmap(shm_ptr, MEM_SIZE);
    shm_unlink(SHM_NAME);

    return 0;
}
