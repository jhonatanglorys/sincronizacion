#ifndef BOOK_H
#define BOOK_H
#include <stdio.h>
#include <pthread.h>

typedef struct book{
    long id;
    char name[8];
    int num_pages;
    int pub_year;
    int status;
    pthread_mutex_t lock;
}book;

void init(book *b);
void setId(book *b, long num);
long getId(book *b);
void setName(book *b, char nam);
char getName(book *b);
void setPage(book *b, int num);
int getPages(book *b);
void setYear(book *b, int num);
int getYear(book *b);
int getStatus(book *b);
void changeStatus(book *b);


#endif