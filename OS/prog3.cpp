#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t a = fork();
    cout << "a: " << acct << "\n";
    if(a == 0)
    {
        cout << "The child process number is " << getpid() << "\n"; 
        cout << "The parent process number is " << getppid() << "\n"; 
        sleep(20);
        cout << "\nThis is the exmaple of orphan process\n";
        exit(0);
    }
    else
    {
        sleep(5);
        cout << "Parent process ID is " << getpid() << "\n";
        cout << "The Parent process number is " << getppid() << "\n";
        cout << "Parent Teminates" << "\n";
    }
    return 0;
}