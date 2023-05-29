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
        cin >> n;
        int mx = 0;
        scanf("%s", s + 1);
        for (int i = 1, p = 0; i <= n; i++)
        {
            if (s[i] == s[i - 1])
                ++p;
            else
                p = 1;
            mx = max(mx, p);
        }
        printf("%d\n", mx + 1);
    }
    return 0;
}

