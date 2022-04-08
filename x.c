#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_NAME_LEN 100
#define MAX_BOOKS 100

typedef struct MyLibrary
{
    int accessionNum;
    char title[MAX_TITLE_LEN];
    char authorName[MAX_NAME_LEN];
    int price;
    bool isIssued;
}myLibrary;

void addBook(myLibrary *);
void displayBook(myLibrary *);
void displayAuthorBooks(myLibrary *);
void displayTitle(myLibrary *);
void displayCount();
void sortBooks(myLibrary *);
int cmpFunc(const void *a, const void *b);

int noOfBooksPresent = 0;

int main()
{
    
    myLibrary (*bookArr);
    bookArr = (myLibrary*)malloc(MAX_BOOKS*sizeof(myLibrary));
    if (bookArr == NULL)
    {
        printf("Memory Allocation Failed");
        return 1;
    }
    
    addBook(bookArr);
    addBook(bookArr);
    addBook(bookArr);
    addBook(bookArr);
    // displayBook(bookArr);
    // displayAuthorBooks(bookArr);
    // displayTitle(bookArr);
    // displayCount(bookArr);
    sortBooks(bookArr);
    free(bookArr);
    return 0;
}

void addBook(myLibrary *bookArr)
{
    if(noOfBooksPresent >= MAX_BOOKS)
    {
        printf("Maximum Limit of Bokks reached");
        return;
    }
    
    printf("Enter the accession Number: ");
    scanf("%d",&bookArr[noOfBooksPresent].accessionNum);
    printf("Enter the title: ");
    scanf("%s",bookArr[noOfBooksPresent].title);
    printf("Enter the author name: ");
    scanf("%s",bookArr[noOfBooksPresent].authorName);
    printf("Enter the price: ");
    scanf("%d",&bookArr[noOfBooksPresent].price); 
    noOfBooksPresent ++;
    
    return;   
}

void displayBook(myLibrary *bookArr)
{
    int accessionNum;
    printf("Enter the accession Number: ");
    scanf("%d",&accessionNum);
    bool bookFound = false;
    
    for(int i = 0; i < noOfBooksPresent; i++)
    {
        if(accessionNum == bookArr[i].accessionNum)
        {
            bookFound = true;
            printf("The title of Book is %s\n",bookArr[i].title);
            printf("The author name is %s\n",bookArr[i].authorName);
            printf("The Price of book is %d\n",bookArr[i].price); 
        }
    }
    
    if(bookFound == false)
    {
        printf("Book not found");
        return;
    }
    return;
}

void displayAuthorBooks(myLibrary * bookArr)
{
    char authorName[MAX_NAME_LEN];
    printf("Enter the author name: ");
    scanf("%s",authorName);
    
    bool bookFound = false;
    
    for(int i = 0; i < noOfBooksPresent; i++)
    {
        if(strcmp(authorName, bookArr[i].authorName) == 0)
        {
            bookFound = true;
            printf("The Accesion number of book is %d\n",bookArr[i].accessionNum);
            printf("The title of Book is %s\n",bookArr[i].title);
            printf("The Price of book is %d\n",bookArr[i].price);
        }
    }
    
    if (bookFound == false)
    {
        printf("Book not found");
        return;
    }
    return;
}

void displayTitle(myLibrary * bookArr)
{
    int accessionNum;
    printf("Enter the accession Number: ");
    scanf("%d",&accessionNum);
    
    bool bookFound = false;
    
    for(int i = 0; i < noOfBooksPresent; i++)
    {
        if(accessionNum == bookArr[i].accessionNum)
        {
            printf("The title of book is %s\n",bookArr[i].title);
            bookFound = true;
        }
    }
    
    if (bookFound == false)
    {
        printf("Book not found");
        return;
    }
    return;
}

void displayCount()
{
    printf("Total no of books are %d\n",noOfBooksPresent);
    return;
}

void sortBooks(myLibrary *bookArr)
{
    qsort(bookArr,noOfBooksPresent,sizeof(myLibrary),cmpFunc);
    
    for(int i = 0; i < noOfBooksPresent; i++)
    {
        printf("The Accesion number of book is %d\n",bookArr[i].accessionNum);
        printf("The title of Book is %s\n",bookArr[i].title);
        printf("The author name is %s\n",bookArr[i].authorName);
        printf("The Price of book is %d\n",bookArr[i].price); 
    }
    return;
}

int cmpFunc(const void *a, const void *b)
{
    myLibrary* a1 = (myLibrary *)(a);
    myLibrary* b1 = (myLibrary *)(b);

    return (a1->accessionNum - b1->accessionNum);
}


