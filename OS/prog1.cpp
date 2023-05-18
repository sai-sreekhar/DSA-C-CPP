#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
int main()
{
    int p = fork();
    cout << p << "\n";
    if (p == 0)
    {
        printf("Hello World1\n");
    }
    else
    {
        printf("Hello World2\n");
    }
    return 0;
}