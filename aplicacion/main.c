#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "book.h"

#define NUMLIBROS 10000;

void* prestar (void* parametros);
int prestamos[4];
book libros[10000];

int main(){
    long i;
    for(i=0; i<10000;i++){
        setId((libros+i),i); 
    }
    printf("El primer ID es %ld y el ultimo id es %ld\n",getId(&libros[0]), getId(&libros[9999]));
    return 0;
}

void* prestar(void* parametros){
   
}