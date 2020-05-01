#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"

#define NUMLIBROS 10000;

void* prestar (void* parametros);
int prestamos[4];
book libros[10000];

int main(){
    long i;
    for(i=0; i<10000;i++){
        setYear((libros+i),2020);
        setPage((libros+i),100);
        setId((libros+i),i);
        strcpy(libros[i].name, "Book_");
    }
    printf("El primer ID es %ld, se llama %c,  tiene %d paginas y fue publicado en el año %d\n",getId(&libros[0]),getName(&libros[0]), getPages(&libros[0]), getYear(&libros[0]));
    printf("El ultimo ID es %ld, se llama %c, tiene %d paginas y fue publicado en el año %d\n",getId(&libros[9999]), getName(&libros[9999]),getPages(&libros[9999]), getYear(&libros[9999]));
    return 0;
}

void* prestar(void* parametros){
   
}