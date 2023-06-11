#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N];

bool check(int x)
{
    int t = 0, pre = -2e9;
    for (int i = 1; i <= n; i++)
        if (a[i] - pre >= x * 2 + 1)
            pre = a[i], ++t;
    return t <= 3;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int L = 0, R = 1e9, ans = 1e9;
        while (L <= R)
        {
            int mid = (L + R) / 2;
            if (check(mid))
                ans = mid, R = mid - 1;
            else
                L = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

