#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t pid = fork();
    cout << "pid: " << pid << "\n";
    if(pid > 0)
    {
        sleep(5);
        cout << "This is an  exmaple of zombie process and id is " << getpid() << "\n";
    }
    else
    {
        cout << "Welcome " << getppid() << "\n";
        exit(0);
    }
    return 0;
}