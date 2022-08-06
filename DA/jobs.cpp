#include <iostream>

#define MAX_SIZE 100
using namespace std;

int jobs[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enQueue(int element)
{
    if (isFull())
        cout << "Queue is full\n";
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX_SIZE;
        jobs[rear] = element;
    }
}

int deQueue()
{
    int element;
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else
    {
        element = jobs[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return (element);
    }
}

void display()
{
    int i;
    if (isEmpty())
        cout << "Empty Queue\n";
    else
    {
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            printf("Job at pos %d is %d", i + 1, jobs[i]);
        }
    }
}

int search(int valToSearch)
{
    int ptr = front;
    while (ptr != rear)
    {
        if (jobs[ptr] == valToSearch)
            return true;
        if (jobs[ptr] > valToSearch)
            return false;
        ptr = (ptr + 1) % MAX_SIZE;
    }
    return false;
}

int main()
{

    int opt;
    cout << "Enter 1 to Add a Job, 2 to remove a Job, 3 to check Status, 4 to display, 0 to Quit: ";
    cin >> opt;
    while (opt != 0)
    {
        int job;
        switch (opt)
        {
        case 1:
            cout << "Enter the Job: ";
            cin >> job;
            enQueue(job);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            cout << "Enter the Job to search: ";
            cin >> job;
            search(job);
            break;
        case 4:
            display();
            break;
        default:
            cout << "Entered Invalid Option"
                 << "\n";
            break;
        }
        cout << "Enter 1 to Add a Job, 2 to remove a Job, 3 to check Status, 4 to display, 0 to Quit: ";
        cin >> opt;
    }
    return 0;
}