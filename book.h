#ifndef BOOK_H
#define BOOK_H

struct Book{
    int id;
    char title[100];
    char author[50];

};

void addBooK();
void deleteBook(int id);
void searchBook(int id);
void listBooks();
  
  #endif
