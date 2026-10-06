#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fallo al crear el proceso
        fprintf(stderr, "Error al ejecutar fork()\n");
        return 1;
    } else if (pid == 0) {
        // Bloque del proceso hijo: Imprime del 10,000 al 1
        for (int i = 10000; i >= 1; i--) {
            printf("Hijo: %d\n", i);
        }
    } else {
        // Bloque del proceso padre: Imprime del 1 al 10,000
        for (int i = 1; i <= 10000; i++) {
            printf("Padre: %d\n", i);
        }
        // Espera a que el proceso hijo termine para que no quede huérfano
        wait(NULL); 
    }

    return 0;
}
