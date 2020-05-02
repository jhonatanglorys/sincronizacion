#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "book.h"

#define NUMLIBROS 10000;
#define PRESTAMOS 1000;

void* prestar_uno (void* parametros);
void* prestar_dos (void* parametros);
void* prestar_tres (void* parametros);
void* prestar_cuatro (void* parametros);
int prestamos[4] = {0,0,0,0};
book libros[10000];
double tiempo[4]={0,0,0,0};

int main(){
    long i;
    for(i=0; i<10000;i++){
        init((libros+i));
        setYear((libros+i),2020);
        setPage((libros+i),100);
        setId((libros+i),i);
        strcpy(libros[i].name, "Book_");
    }
    //printf("El primer ID es %ld, se llama %c,  tiene %d paginas, fue publicado en el año %d y su estado es %d disponible\n",getId(&libros[0]),getName(&libros[0]), getPages(&libros[0]), getYear(&libros[0]),getStatus(&libros[0]));
    //printf("El ultimo ID es %ld, se llama %c, tiene %d paginas, fue publicado en el año %d y su estado es %d disponible\n",getId(&libros[9999]), getName(&libros[9999]),getPages(&libros[9999]), getYear(&libros[9999]), getStatus(&libros[9999]));
    pthread_t threads_id[4];
    
    
    
    pthread_create(&threads_id[1],NULL, &prestar_uno,NULL);
    pthread_create(&threads_id[2],NULL, &prestar_dos,NULL);
    pthread_create(&threads_id[3],NULL, &prestar_tres,NULL);
    pthread_create(&threads_id[4],NULL, &prestar_cuatro,NULL);
    pthread_join(threads_id[1],NULL);
    pthread_join(threads_id[2],NULL);
    pthread_join(threads_id[3],NULL);
    pthread_join(threads_id[4],NULL);
    printf("El puesto 1 hizo un total de %d préstamos exitosos y %d fallidos\n", prestamos[0], 1000-prestamos[0]);
    printf("El puesto 2 hizo un total de %d préstamos exitosos y %d fallidos\n", prestamos[1], 1000-prestamos[1]);
    printf("El puesto 3 hizo un total de %d préstamos exitosos y %d fallidos\n", prestamos[2], 1000-prestamos[2]);
    printf("El puesto 4 hizo un total de %d préstamos exitosos y %d fallidos\n", prestamos[3], 1000-prestamos[3]);
    long long tiempo_total=(tiempo[0]+tiempo[1]+tiempo[2]+tiempo[3]);
    printf("El tiempo total requerido para los préstamos fue de %g milisegundos\n", tiempo_total);
    int exitosos= prestamos[0]+prestamos[1]+prestamos[2]+prestamos[3];
    printf("El número total de préstamos exitosos fue de %d y los fallidos fueron %d\n", exitosos, 4000-exitosos);
    printf("El número de libros restantes por prestar son %d\n", 10000-exitosos);
    return 0;
}

void* prestar_uno(void* parametros){
    struct timeval ti, tf;
    gettimeofday(&ti, NULL);   // Instante inicial
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
   gettimeofday(&tf, NULL);   // Instante final
   tiempo[0]= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
}
void* prestar_dos(void* parametros){
    struct timeval ti, tf;
    gettimeofday(&ti, NULL);   // Instante inicial
    time_t t;
    int j;
    int aleatorio;
    srand((unsigned) time(&t));
    for (j=0; j<1000;j++){
        aleatorio=rand() % 9999;
        //aleatorio=j;
        if(getStatus((libros+aleatorio))){
            changeStatus((libros+aleatorio));
            prestamos[1]++;
        }
        
    }
   gettimeofday(&tf, NULL);   // Instante final
   tiempo[1]= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
}
void* prestar_tres(void* parametros){
    struct timeval ti, tf;
    gettimeofday(&ti, NULL);   // Instante inicial
    time_t t;
    int j;
    int aleatorio;
    srand((unsigned) time(&t));
    for (j=0; j<1000;j++){
        aleatorio=rand() % 9999;
        //aleatorio=j;
        if(getStatus((libros+aleatorio))){
            changeStatus((libros+aleatorio));
            prestamos[2]++;
        }
        
    }
   gettimeofday(&tf, NULL);   // Instante final
   tiempo[2]= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
}
void* prestar_cuatro(void* parametros){
    struct timeval ti, tf;
    gettimeofday(&ti, NULL);   // Instante inicial
    time_t t;
    int j;
    int aleatorio;
    srand((unsigned) time(&t));
    for (j=0; j<1000;j++){
        aleatorio=rand() % 9999;
        //aleatorio=j;
        if(getStatus((libros+aleatorio))){
            changeStatus((libros+aleatorio));
            prestamos[3]++;
        }
        
    }
   gettimeofday(&tf, NULL);   // Instante final
   tiempo[3]= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
}