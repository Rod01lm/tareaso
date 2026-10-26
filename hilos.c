#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* tarea_hilo(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo -> %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo_id;

    if (pthread_create(&hilo_id, NULL, tarea_hilo, NULL) != 0) {
        perror("Error al crear el hilo");
        return 1;
    }

    for (int i = 1; i <= 10000; i++) {
        printf("Principal -> %d\n", i);
    }

    if (pthread_join(hilo_id, NULL) != 0) {
        perror("Error al esperar al hilo");
        return 2;
    }

    return 0;
}

