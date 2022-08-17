#include <iostream>

using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases > 0)
    {
        int n, q;
        cin >> n >> q;
        int stops[n];
        for (int i = 0; i < n; i++)
        {
            cin >> stops[i];
        }

        int res = 0;
        for (int i = 0; i < q; i++)
        {
            int s1, s2;
            cin >> s1 >> s2;

            int pos = -1;

            for (int i = 0; i < n; i++)
            {
                if (stops[i] == s1)
                {
                    pos = i;
                    break;
                }
            }

            if (pos == -1)
            {
                continue;
            }

            for (int i = pos; i < n; i++)
            {
                if (stops[i] == s2)
                {
                    res++;
                    break;
                }
            }
        }
        cout << res << "\n";
        testCases--;
    }

    return 0;
}

/*
1 4 5 6 6 8
*/