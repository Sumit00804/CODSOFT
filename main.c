#include <stdio.h>
#include "book.h"

int main() {
    int option, id;

    while (1) {
        printf("\n============================\n");
        printf("      Book Management System\n");
        printf("============================\n");
        printf("1. Add a new book\n");
        printf("2. Search for a book by ID\n");
        printf("3. List all books\n");
        printf("4. Delete a book by ID\n");
        printf("5. Exit\n");
        printf("============================\n");
        printf("Choose an option (1-5): ");
        
        if (scanf("%d", &option) != 1) 
        {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (option) {
            case 1:
                addBook();
                break;

            case 2:
                printf("Enter the ID of the book to search: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input! Please enter a valid ID.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    continue;
                }
                searchBook(id);
                break;

            case 3:
                listBooks();
                break;

            case 4:
                printf("Enter the ID of the book to delete: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input! Please enter a valid ID.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    continue;
                }
                deleteBook(id);
                break;

            case 5:
                printf("Exiting the program... Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please choose between 1 and 5.\n");
        }
    }

    return 0;
}
