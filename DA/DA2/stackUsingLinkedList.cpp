#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *top = NULL;

void push(int data)
{
    node *newNode = new node;

    if (!newNode)
    {
        cout << "Memory Allocation Failed\n";
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    return;
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

void search(int data)
{
    int pos = 0;
    node *currNode = top;
    while ((currNode != NULL) && (currNode->data != data))
    {
        pos++;
        currNode = currNode->next;
    }

    if (currNode == NULL)
    {
        cout << "Not Found\n";
        return;
    }

    if (currNode->data == data)
    {
        cout << "Found at Pos " << pos + 1 << "\n";
        return;
    }
}

void pop()
{
    node *nodeToPop;

    if (top == NULL)
    {
        cout << "Stack Underflow\n";
        return;
    }

    nodeToPop = top;
    top = top->next;

    cout << "Popped Node has data " << nodeToPop->data << "\n";
    free(nodeToPop);
}

void display()
{

    if (top == NULL)
    {
        cout << "Stack is Empty\n";
        return;
    }

    node *currNode = top;
    while (currNode != NULL)
    {

        cout << currNode->data << "-> ";
        currNode = currNode->next;
    }
}

int main()
{
    int opt;
    cout << "Enter 1 to Push, 2 to Pop, 3 to Search, 4 to Display, 0 to Quit: ";
    cin >> opt;
    while (opt != 0)
    {
        int data;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the Value: ";
            cin >> data;

            push(data);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            cout << "Enter the Value: ";
            cin >> data;
            search(data);
            break;
        }
        case 4:
        {
            display();
            break;
        }
        default:
        {
            cout << "Entered Invalid Option"
                 << "\n";
            break;
        }
        }
        cout << "Enter 1 to Push, 2 to Pop, 3 to Search, 4 to Display, 0 to Quit: ";
        cin >> opt;
    }
    return 0;
}
