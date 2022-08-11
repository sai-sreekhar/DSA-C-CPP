#include <iostream>
#include <string>

#define MAX_SIZE 10

using namespace std;

typedef struct Job
{
    string name;
    int salary;
    int duration;
} job;

job jobQueue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enQueue(job *jobInput)
{
    if (isFull())
    {
        cout << "Queue is full\n";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX_SIZE;
        jobQueue[rear] = *jobInput;
    }
}

void deQueue()
{
    int element;
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    else
    {
        job deQueuedJob = jobQueue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }

        cout << "Dequed Job name: " << deQueuedJob.name << " salary: " << deQueuedJob.salary << " duration " << deQueuedJob.duration << "\n";
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Empty Queue\n";
    }
    else
    {
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "Job at pos " << i + 1 << " has name: " << jobQueue[i].name << " salary: " << jobQueue[i].salary << " duration: " << jobQueue[i].duration << "\n";
            }
        }
        else
        {
            for (int i = front; i < MAX_SIZE; i++)
            {
                cout << "Job at pos " << i + 1 << " has name: " << jobQueue[i].name << " salary: " << jobQueue[i].salary << " duration: " << jobQueue[i].duration << "\n";
            }

            for (int i = 0; i <= rear; i++)
            {
                cout << "Job at pos " << i + 1 << " has name: " << jobQueue[i].name << " salary: " << jobQueue[i].salary << " duration: " << jobQueue[i].duration << "\n";
            }
        }
    }
}

void search(string jobName)
{
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            if (jobQueue[i].name == jobName)
            {
                cout << "Found. Job has name: " << jobQueue[i].name << " salary: " << jobQueue[i].salary << " duration: " << jobQueue[i].duration << "\n";
                return;
            }
        }
    }
    else
    {
        for (int i = front; i < MAX_SIZE; i++)
        {
            if (jobQueue[i].name == jobName)
            {
                cout << "Found. Job has name: " << jobQueue[i].name << " salary: " << jobQueue[i].salary << " duration: " << jobQueue[i].duration << "\n";
                return;
            }
        }

        for (int i = 0; i <= rear; i++)
        {
            if (jobQueue[i].name == jobName)
            {
                cout << "Found. Job has name: " << jobQueue[i].name << " salary: " << jobQueue[i].salary << " duration: " << jobQueue[i].duration << "\n";
                return;
            }
        }
    }
    cout << "Not Found"
         << "\n";
    return;
}

int main()
{
    int opt;
    cout << "Enter 1 to Add a Job, 2 to remove a Job, 3 to search or check status, 4 to display, 0 to Quit: ";
    cin >> opt;
    while (opt != 0)
    {
        job jobInput;
        string jobName;
        switch (opt)
        {
        case 1:
            cout << "Enter the Job Name: ";
            cin >> jobInput.name;
            cout << "Enter the Job salry: ";
            cin >> jobInput.salary;
            cout << "Enter the Job duration: ";
            cin >> jobInput.duration;
            enQueue(&jobInput);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            cout << "Enter the Job Name to search: ";
            cin >> jobName;
            search(jobName);
            break;
        case 4:
            display();
            break;
        default:
            cout << "Entered Invalid Option"
                 << "\n";
            break;
        }
        cout << "Enter 1 to Add a Job, 2 to remove a Job, 3 to search or check status, 4 to display, 0 to Quit: ";
        cin >> opt;
    }
    return 0;
}