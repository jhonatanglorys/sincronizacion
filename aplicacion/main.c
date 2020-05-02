#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"

#define NUMLIBROS 10000;
#define PRESTAMOS 1000;

void* prestar (void* parametros);
int prestamos[4] = {0,0,0,0};
book libros[10000];

int main(){
    long i;
    for(i=0; i<10000;i++){
        init((libros+i));
        setYear((libros+i),2020);
        setPage((libros+i),100);
        setId((libros+i),i);
        strcpy(libros[i].name, "Book_");
    }
    printf("El primer ID es %ld, se llama %c,  tiene %d paginas, fue publicado en el año %d y su estado es %d disponible\n",getId(&libros[0]),getName(&libros[0]), getPages(&libros[0]), getYear(&libros[0]),getStatus(&libros[0]));
    printf("El ultimo ID es %ld, se llama %c, tiene %d paginas, fue publicado en el año %d y su estado es %d disponible\n",getId(&libros[9999]), getName(&libros[9999]),getPages(&libros[9999]), getYear(&libros[9999]), getStatus(&libros[9999]));
    pthread_t threads_id;
    pthread_create(&threads_id,NULL, &prestar,NULL);
    pthread_join(threads_id,NULL);
    printf("El puesto 0 hizo un total de %d préstamos exitosos y %d fallidos\n", prestamos[0], 1000-prestamos[0]);
    return 0;
}

void* prestar(void* parametros){
    time_t t;
    int j;
    int aleatorio;
    srand((unsigned) time(&t));
    for (j=0; j<1000;j++){
        aleatorio=rand() % 9999;
        //aleatorio=j;
        if(getStatus((libros+aleatorio))){
            changeStatus((libros+aleatorio));
            prestamos[0]++;
        }
        
    }
   
}