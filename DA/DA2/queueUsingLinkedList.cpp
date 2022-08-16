#include <iostream>

using namespace std;

typedef struct Node
{
    string name;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

void insert(string name)
{
    node *newNode = new node;
    if (newNode == NULL)
    {
        cout << "Memory Alocation Failed\n";
        return;
    }

    newNode->name = name;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    return;
}

void remove()
{
    if (front == NULL)
    {
        cout << "Underflow\n";
        return;
    }

    node *newFront = front->next;
    delete front;
    front = newFront;
}

int search(string inputName)
{
    int count = 0;
    node *currNode = front;
    bool found = false;
    while (currNode != NULL)
    {
        count++;
        if (currNode->name == inputName)
        {
            found = true;
            cout << "Patient Found at pos " << count << " has name " << currNode->name << "\n";
            return count;
        }

        currNode = currNode->next;
    }

    if (!found)
    {
        cout << "Patient Not Found\n";
    }

    return -1;
}

void update(string oldName, string newName)
{
    if (search(oldName) == -1)
    {
        cout << "Patient Not Found\n";
        return;
    }

    node *currNode = front;
    while (currNode->name != oldName)
    {
        currNode = currNode->next;
    }

    currNode->name = newName;
    return;
}

void display()
{
    int count = 0;
    node *currNode = front;
    while (currNode != NULL)
    {
        count++;
        cout << "Patient at pos " << count << " has name " << currNode->name << "\n";
        currNode = currNode->next;
    }
    return;
}

int main()
{

    int opt;
    cout << "Enter 1 to Insert, 2 to Delete, 3 to Search, 4 to Update, 5 to Display, 0 to Quit: ";
    cin >> opt;
    while (opt != 0)
    {
        string name;
        string newName;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter The Name of the Patient: ";
            cin >> name;
            insert(name);
            break;
        }
        case 2:
        {
            remove();
            break;
        }
        case 3:
        {
            cout << "Enter the Name of the Patient to search: ";
            cin >> name;
            search(name);
            break;
        }
        case 4:
        {
            cout << "Enter the OldName and NewName of Patient: ";
            cin >> name >> newName;
            update(name, newName);
            break;
        }
        case 5:
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
        cout << "Enter 1 to Insert, 2 to Delete, 3 to Search, 4 to Update, 5 to Display, 0 to Quit: ";
        cin >> opt;
    }
    return 0;
}