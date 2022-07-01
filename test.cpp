#include <iostream>
#include <string>
#include <cstring>
#include <new>
#include <cstdbool>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstdarg>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024+2] = { 0 };

    snprintf(buffer, sizeof(buffer), "%s(%d) : " , fileName, line);
    int stringLength = strnlen(buffer,1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer+stringLength,remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

int main()
{
    string ans = "";
    string presentStr = "";
    for(int i = 1; i<3; i++)
    {
        if (i == 1)
        {
            ans.append("()");
            presentStr = "()";
        }       
        else
        {
            ans.append("("+presentStr+")");
        }
    }
    
    string str1 = "(";
    str1.append(ans);
    ans.append(")");
    cout << ans << endl;
    return 0;
}