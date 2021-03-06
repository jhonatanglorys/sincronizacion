#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "counter.h"


/* structs */
// code here (if you required it)...

/* start_routine header */
// code here...
void* sumar (void* parametros);
int valorMaximo =0;
int numHilos = 0;
int threeshold = 0;


/* Global variables */
// code here (if you required it)...
counter_t *contador;


int main(int argc, char *argv[]) { 

     if(argc>2){  
    /* get the command's line parameters */
    // code here...
    threeshold = atoi(argv[1]);
    valorMaximo = atoi(argv[2]);
    numHilos = atoi(argv[3]);

    /* Declaration of struct timeval variables */
    // code here...
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);   // Instante inicial

    /* Initializing conter */
    // code here...
    init(&contador, threeshold);

    /* Threads handlers */
    // code here...

    int i;
    pthread_t threads_id[argc];
    

    for(i=1; i<argc;i++){
        pthread_create(&threads_id[i],NULL, &sumar,&i);
    }

    for(i=1; i<argc;i++){
        pthread_join(threads_id[i],NULL);
    }

    /* Time stops counting here */
    // code here...
     gettimeofday(&tf, NULL);   // Instante final

    /* get the end time */
    // code here...
    tiempo= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;

    /* get the elapset time (end_time - start_time) */
    // code here...


    /* print the results (number threads employed, counter value, elasep time) */
    // code here...
    printf("Se han empleado %d hilos para aumentar hasta %d el contador usando un threeshold de %d y tomó %g milisegundos para completarlo\n", numHilos, get(&contador),threeshold, tiempo);
    }
    return 0;
}

/* start_routine definition */
// code here...

void* sumar(void* parametros){
    int threadId = *((int*)parametros);
    int i;
    for(i=0; i<(valorMaximo/3);i++){
        update(&contador, threadId,1);
    }
}



