#include "book.h"
#include <stdio.h>
#include <string.h>

struct Book books[100];  // Creating array to store up to 100 books

int totalBooks = 0;      // Counter for number of books added

// Function for adding a new book to the store
void addBook() {
    struct Book newBook;
    
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    
    printf("Enter Book Title: ");
    scanf(" %[^\n]", newBook.title);  // To read all characters until a newline character is encountered
    
    printf("Enter Book Author: ");
    scanf(" %[^\n]", newBook.author);

    books[totalBooks] = newBook;  // Add book to the store
    totalBooks++;                 // Increasing the index count
    
    printf("Book added successfully!\n");
}

// Function for searching a book in the main array books store
void searchBook(int id) {
    int found = 0;  // To track if the book was found

    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == id) {
            printf("\nBook found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with ID %d.\n", id);
    }
}

// Function for showing the list of books
void listBooks() {
    if (totalBooks == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nListing all books:\n");
    for (int i = 0; i < totalBooks; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
    }
}

// Function for deleting books based on ID
void deleteBook(int id) {
    int found = 0;

    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < totalBooks - 1; j++) {
                books[j] = books[j + 1];  // Shift all elements by one step to the left
            }
            totalBooks--;  // Decrease the total book count
            printf("Book with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if (!found) {
        printf("No book found with ID %d for delete.\n", id);
    }
}
