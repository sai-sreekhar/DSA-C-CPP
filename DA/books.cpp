#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 100

typedef struct Book
{
    string title;
    string author;
    int pages;
    int year;
} book;

book bookStack[MAX_SIZE];
int top = -1;

void push(book *inputBook)
{
    if (top == -1)
    {
        bookStack[0] = *inputBook;
        top = 0;
        return;
    }

    if (top == MAX_SIZE - 1)
    {
        cout << "OVERFLOW\n";
        return;
    }

    top++;
    bookStack[top] = *inputBook;
    return;
}

void pop()
{
    if (top == -1)
    {
        cout << "UNDERFLOW\n";
        return;
    }

    cout << "Popped Element has Title: " << bookStack[top].title << ", Author: " << bookStack[top].author << ", Pages " << bookStack[top].pages << ", Year of Publication: " << bookStack[top].year << "\n";
    top--;
    return;
}

void search(string title)
{
    for (int i = 0; i <= top; i++)
    {
        if (bookStack[top].title == title)
        {
            cout << "Book Found at Pos " << i + 1 << "\n";
            return;
        }
    }
    cout << "Book Not Found\n";
    return;
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << "Book at pos " << i + 1 << " has Title: " << bookStack[i].title << ", Author: " << bookStack[i].author << ", Pages " << bookStack[i].pages << ", Year of Publication: " << bookStack[i].year << "\n";
    }
}

int main()
{
    int opt;
    cout << "Enter 1 to Push, 2 to Pop, 3 to Search, 4 to display, 0 to Quit: ";
    cin >> opt;
    while (opt != 0)
    {
        book inputBook;
        string title;
        switch (opt)
        {
        case 1:
            cout << "Enter The Title of the book: ";
            cin >> inputBook.title;
            cout << "Enter The Author of the book: ";
            cin >> inputBook.author;
            cout << "Enter The Number of Pages of book: ";
            cin >> inputBook.pages;
            cout << "Enter The Year of Publication of the book: ";
            cin >> inputBook.year;
            push(&inputBook);
            break;
        case 2:
            pop();
            break;
        case 3:
            cout << "Enter the Title of Book to search: ";
            cin >> title;
            search(title);
            break;
        case 4:
            display();
            break;
        default:
            cout << "Entered Invalid Option"
                 << "\n";
            break;
        }
        cout << "Enter 1 to Push, 2 to Pop, 3 to Search, 4 to display, 0 to Quit: ";
        cin >> opt;
    }
    return 0;
}