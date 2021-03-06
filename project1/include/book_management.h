#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H

#include <string.h>
#include "global.h"
#include <stdio.h>
#include <stdlib.h>

extern Book* headPtrBook;
extern char answer[];

//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books();
//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books();
//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(char bookTitle[], char bookAuthors[], unsigned int bookCopies, unsigned int bookYear);
//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(char title[], char authors[],unsigned int year);
//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_title (const char *title);
//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_author (const char *author);
//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_year (unsigned int year);
// function to find book by id
Book* findBookByID (unsigned int id);
// function to borrow books for user
void borrowBook(Book *book, User user);
// function to check if the user borrow two same book
int checkSameBorrowBook(unsigned int id, User user);
// function to check the returned book
BorrowBook* checkReturnBook(unsigned int id, User user);
// function to return the book
void returnBook(BorrowBook* returnBook, User user);
// function to search for a book
void searchForBook(char menu[]);
// function to free book memory
void freeBook();
// function to free book array memory
void freeBookArray(BookArray bookArray);
#endif