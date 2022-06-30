#include <iostream>
#include<bits/stdc++.h>
#include <cstdlib>
#include <new>
#include <cmath>
#include <cstring>
#include <cstdbool>
#include <cctype>
#include <cstdarg>
#include <climits>

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

bool isScramble(string S1, string S2)
{
	if (S1.length() != S2.length()) {
		return false;
	}

	int n = S1.length();

	if (n == 0) {
		return true;
	}

	if (S1 == S2) {
		return true;
	}

	string copy_S1 = S1, copy_S2 = S2;

	sort(copy_S1.begin(), copy_S1.end());
	sort(copy_S2.begin(), copy_S2.end());

	if (copy_S1 != copy_S2) {
		return false;
	}

	for (int i = 1; i < n; i++) {

		if (isScramble(S1.substr(0, i), S2.substr(0, i))
			&& isScramble(S1.substr(i, n - i),
						S2.substr(i, n - i))) {
			return true;
		}

		if (isScramble(S1.substr(0, i),
					S2.substr(n - i, i))
			&& isScramble(S1.substr(i, n - i),
						S2.substr(0, n - i))) {
			return true;
		}
	}

	return false;
}

unordered_map <string,int>mem;

bool solveScrambleMemoize(string s1, string s2)
{
    if (s1.size() == 1)
        return s1 == s2;

    if (s1 == s2)
        return true;

    string key = s1 + "*" + s2;

    if (mem.find(key) != mem.end())
        return mem[key];

    int n = s1.size();
    bool res = false;

    for (int i = 1; i < n; ++i)
    {
        if ((solveScrambleMemoize(s1.substr(0, i), s2.substr(0, i)) and solveScrambleMemoize(s1.substr(i), s2.substr(i))) or (solveScrambleMemoize(s1.substr(0, i), s2.substr(n - i)) and solveScrambleMemoize(s1.substr(i), s2.substr(0, n - i))))
            return mem[key] = true;
    }

    return mem[key] = false;
}

int main()
{
	string S1 = "coder";
	string S2 = "ocred";

	if (isScramble(S1, S2)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No"<< endl;
	}

    if (solveScrambleMemoize(S1, S2))
        cout << "Yes the string " << S2 << " is a scramble string of " << S1 << endl;
    else
        cout << "No, the string " << S2 << " is not a scramble string of " << S1 << endl;

	return 0;
}
