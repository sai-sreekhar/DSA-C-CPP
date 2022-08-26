#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000
typedef enum Role
{
    VISITOR = 1,
    STUDENT = 2,
    SCHOLAR = 3,
    FACULTY = 4,
    OTHER = 0

} role;

typedef struct Person
{
    string name;
    role personRole;
} person;

person priorityQueue[MAX_SIZE];

int lastIdx = -1;

void enqueue(string name, string role)
{
    if (lastIdx  == MAX_SIZE -1)
    {
        cout << "OVERFLOW\n";
        return;
    }
    
    lastIdx++;

    priorityQueue[lastIdx].name = name;

    if (role == "visitor")
    {
        priorityQueue[lastIdx].personRole = VISITOR;
    }
    else if (role == "student")
    {
        priorityQueue[lastIdx].personRole = STUDENT;
    }
    else if (role == "scholar")
    {
        priorityQueue[lastIdx].personRole = SCHOLAR;
    }
    else if (role == "faculty")
    {
        priorityQueue[lastIdx].personRole = FACULTY;
    }
    else
    {
        priorityQueue[lastIdx].personRole = OTHER;
    }
}

int peek()
{
    int highestPriority = -1;
    int idx = -1;

    for (int i = 0; i <= lastIdx; i++)
    {
        if (highestPriority < priorityQueue[i].personRole)
        {
            highestPriority = priorityQueue[i].personRole;
            idx = i;
        }
    }

    cout << "Highest Priority Person has name: " << priorityQueue[idx].name << "\n";
    return idx;
}

void dequeue()
{
    int idx = peek();

    for (int i = idx; i < lastIdx; i++)
    {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    lastIdx--;
}

void display()
{
    if (lastIdx == -1)
    {
        cout << "Priority Queue is Empty\n";
        return;
    }

    for (int i = 0; i <= lastIdx; i++)
    {
        cout << "Position: " << i + 1 << " Name: " << priorityQueue[i].name << " Role: " << priorityQueue[i].personRole << "\n";
    }
    return;
}

int main()
{
    int opt;
    cout << "Enter 1 to Enqueue, 2 to Dequeue, 3 to Display, 0 to Quit: ";
    cin >> opt;
    while (opt != 0)
    {
        string name;
        string role;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter The Name of the Person: ";
            cin >> name;
            cout << "Enter the role: ";
            cin >> role;
            enqueue(name, role);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
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
        cout << "Enter 1 to Enqueue, 2 to Dequeue, 3 to Display, 0 to Quit: ";
        cin >> opt;
    }
    return 0;
}
