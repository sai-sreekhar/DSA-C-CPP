#include <iostream>
#include <string>
#include <new>
#include <cstdbool>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *head = NULL;
node *tail = NULL;

void insertAtTail(int data)
{
    node *newNode = NULL;
    // try
    // {
    //     // newNode = new node;
    //     // newNode->data = data;
    //     throw (std::invalid_argument("Data Invalid"));
    // }
    // catch(bad_alloc xa)
    // {
    //     cout << "Allocation Failure";
    //     return;
    // }
    // catch(exception& e)
    // {
    //     cout << "In genric exception exception catched\n" << e.what() << endl;
    //     return;
    // }

    try
    {
        newNode = new Node;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void display()
{
    node *curNode = head;
    int pos = 1;

    while (curNode != NULL)
    {
        cout << "The element as position " << pos << " is " << curNode->data << endl;;
        curNode = curNode->next;
        pos++;
    }

    return;
}

int getLength()
{
    int length = 0;
    node *curNode = head;

    while (curNode != NULL)
    {
        curNode = curNode->next;
        length++;
    }

    return length;
}

void bubbleSort()
{
    int length = getLength();

    if (length == 0)
    {
        cout << "The SinglyLinkedList is Empty\n";
        return;
    }
    
    if (length == 1)
    {
        return;
    }

    node *currentNode = NULL;
    node *nextNode = NULL;

    for (int i = 0; i < length - 1; i++)
    {
        currentNode = head;
        nextNode = head->next;

        for (int j = 0; j < length - i - 1; j++)
        {
            if (currentNode->data > nextNode->data)
            {
                int tempData = currentNode->data;
                currentNode->data = nextNode->data;
                nextNode->data = tempData;
            }

            currentNode = currentNode->next;
            nextNode = nextNode->next;
        }
    }

    return;
}

void convertToArr(node *arr,int length)
{
    node *currNode = head;
    for (int i = 0; i < length; i++)
    {
        arr[i] = *currNode;
        currNode = currNode->next;
    }
}

int cmpfunc (const void * a, const void * b)
{
   return ( ((node*)a)->data - ((node*)b)->data );
}


int main()
{
    insertAtTail(1);
    insertAtTail(10);
    insertAtTail(9);
    insertAtTail(500);
    insertAtTail(8);
    // display();
    // bubbleSort();
    // display();
    int length = getLength();
    node arr[length];
    convertToArr(arr,length); 
    for (int i = 0; i < length; i++)
    {
        cout << arr[i].data  << endl;
    }
    
    qsort(arr,length,sizeof(node),cmpfunc);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i].data  << endl;
    }

    return 0;
}