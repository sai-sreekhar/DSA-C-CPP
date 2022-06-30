#include <iostream>
using namespace std;
int func(int i)
{
    if (i == 1)
    {
        return i;
    }
}
int main()
{
    int i = 5;
    int j = 1;
    cout << func(i) << endl;
    cout << func(j) << endl;
    return 0;
}