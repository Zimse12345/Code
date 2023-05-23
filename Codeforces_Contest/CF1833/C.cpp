#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        int mn = 1000000000, tag = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
            if (a[i] & 1)
                tag = 1;
        }
        if (mn & 1)
            printf("Yes\n");
        else if (tag)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

