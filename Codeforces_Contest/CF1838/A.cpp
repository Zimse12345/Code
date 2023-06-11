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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        if (a[1] < 0)
            printf("%d\n", a[1]);
        else
            printf("%d\n", a[n]);
    }
    return 0;
}

