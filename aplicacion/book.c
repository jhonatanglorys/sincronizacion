#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "book.h"

void init(book *b){
    b->status=1; // 1 igual disponible
    return;
}

void setId(book *b, long num){
    b->id=num;
    return;
}
long getId(book *b){
    return b->id;
}
void setName(book *b, char nam){
    strcpy(b->name,nam); 
    return;
}
char getName(book *b){
    return b->name;
}
void setPage(book *b, int num){
    b->num_pages=num;
    return;
}
int getPages(book *b){
    return b->num_pages;
}
void setYear(book *b, int num){
    b->pub_year=num;
    return;
}
int getYear(book *b){
    return b->pub_year;
}
int getStatus(book *b){
    pthread_mutex_lock(&b->lock);
    return b->status;
    pthread_mutex_unlock(&b->lock);
}
void changeStatus(book *b){
    pthread_mutex_lock(&b->lock);
    b->status=0;// 0 igual a prestado
    pthread_mutex_unlock(&b->lock);
    return;
}