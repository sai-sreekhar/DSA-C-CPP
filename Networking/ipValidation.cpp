/*
    Author: Sai Sreekar
    Created: 2023/05/13 14:06:49
    Last Modified: 2023/05/15 23:35:16
*/

#include <bits/stdc++.h>
using namespace std;

bool isIPV4(string ipStr)
{
    int dotCount = 0;
    bool isBinary = true;
    for (int i = 0; i < ipStr.size(); i++)
    {
        if (ipStr[i] == '.')
        {
            dotCount++;
        }

        if (ipStr[i] != '.' && ipStr[i] != '0' && ipStr[i] != '1')
        {
            isBinary = false;
        }
    }

    if (dotCount == 0 && isBinary)
    {
        return true;
    }

    if (dotCount != 3)
    {
        cout << "The given address isn't ipv4 because the dot count is not equal to 3\n";
        return false;
    }

    vector<string> tokens;

    stringstream check1(ipStr);
    string intermediate;

    while (getline(check1, intermediate, '.'))
    {
        tokens.push_back(intermediate);
    }

    if (tokens.size() != 4)
    {
        cout << "The given address isn't ipv4 because the token count is not equal to 4\n";
        return false;
    }

    for (int i = 0; i < tokens.size(); i++)
    {
        int num = 0;

        if (tokens[i] == "0")
        {
            continue;
        }

        if (tokens[i].size() == 0)
        {
            cout << "The given address isn't ipv4 because oneof the token has a size of 0\n";
            return false;
        }

        for (int j = 0; j < tokens[i].size(); j++)
        {
            if (tokens[i][j] > '9' || tokens[i][j] < '0')
            {
                cout << "The given address isn't ipv4 because one of the token has a non digit character\n";
                return false;
            }

            num *= 10;
            num += tokens[i][j] - '0';

            if (num == 0)
            {
                cout << "The given address isn't ipv4 because one of the token has a leading zero\n";
                return false;
            }
        }

        if (num > 255 || num < 0)
        {
            cout << "The given address isn't ipv4 because one of the token is not in the range of 0 to 255\n";
            return false;
        }
    }

    return true;
}

bool isHex(string ipStr)
{
    for (int i = 0; i < ipStr.length(); i++)
    {
        char ch = ipStr[i];
        if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'F') && (ch < 'a' || ch > 'f'))
        {
            cout << "The given address isn't ipv6 because one of the token has a Non Hex character(Eg: '.')\n";
            return false;
        }
    }

    return true;
}

bool isIPV6(string ipStr)
{
    int colonCount = 0;
    int consecutiveColonCount = 0;
    for (int i = 1; i < ipStr.size(); i++)
    {
        if (ipStr[i] == ':' && ipStr[i - 1] == ':' && consecutiveColonCount == 0)
        {
            consecutiveColonCount++;
            colonCount++;
        }
        else if (ipStr[i] == ':' && ipStr[i - 1] == ':' && consecutiveColonCount == 1)
        {
            cout << "The given address isn't ipv6 because there are more than one consecutive colons\n";
            return false;
        }
        else if (ipStr[i] == ':')
        {
            colonCount++;
        }
    }

    if (consecutiveColonCount == 0 && colonCount != 7)
    {
        cout << "The given address isn't ipv6 because the colon count is equal to 7\n";
        return false;
    }
    
    if (consecutiveColonCount == 1 && colonCount > 7)
    {
        cout << "The given address isn't ipv6 because the format is incorrect\n";
        return false;
    }

    vector<string> tokens;
    stringstream check1(ipStr);
    string intermediate;

    while (getline(check1, intermediate, ':'))
    {
        tokens.push_back(intermediate);
    }

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].size() == 0)
        {
            continue;
        }

        int len = tokens[i].size();

        if (!isHex(tokens[i]))
        {
            return false;
        }

        if (len > 4)
        {
            cout << "The given address isn't ipv6 because one of the token has a size greater than 4\n";
            return false;
        }

        if (len < 1)
        {
            cout << "The given address isn't ipv6 because one of the token has a size less than 1\n";
            return false;
        }
    }
    return true;
}

void checkIPAddress(string ipStr)
{
    if (isIPV4(ipStr))
    {
        cout << "The given address is ipv4\n";
    }
    else if (isIPV6(ipStr))
    {
        cout << "The given address is ipv6\n";
    }
    else
    {
        cout << "The given address is neither ipv4 nor ipv6\n";
    }
}

int main()
{
    string ipStr;
    cin >> ipStr;
    if(ipStr.size() == 0)
    {
        cout << "The given address is neither ipv4 nor ipv6\n";
        return 0;
    }
    checkIPAddress(ipStr);
    return 0;
}
