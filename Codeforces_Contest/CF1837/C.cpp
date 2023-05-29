#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n;
char s[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        s[0] = '0';
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '?')
                s[i] = s[i - 1];
            putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}

