#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
    fork();
    fork();
    cout << "Hello World\n";
    return 0;
}