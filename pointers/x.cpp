/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
void func(int *dp,int x,int y)
{
    // cout << dp << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << *(dp+i*y+j) << endl;
        }
        
    }
    
    return;
}
int main()
{
    int x = 5;
    int y = 6;
    int dp[x][y];
    for(int i =0;i<5;i++)
    {
        for(int j =0;j<6;j++)
        {
            dp[i][j] = i+j;
        }
    }
    cout << &dp[0][0] << endl;
    // cout << "IN Main" << endl;
    // for(int i =0;i<x;i++)
    // {
    //     for(int j =0;j<y;j++)
    //     {
    //         cout << dp[i][j] << endl;
    //     }
    // }
    cout << "FUnction called" << endl;
    func((int*)dp,x,y);
    return 0;
}