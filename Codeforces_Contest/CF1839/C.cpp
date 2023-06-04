#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N], b[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int x = 1, t = 0;
        if (a[n])
            printf("NO\n");
        else
        {
            printf("YES\n");
            a[0] = -1, a[n + 1] = -1;
            for (int i = 1, s = 0; i <= n + 1; i++)
            {
                if (a[i] == a[i - 1])
                    ++s;
                if (a[i] != a[i - 1] || i == n + 1)
                {
                    if (s)
                    {
                        x += s - 1;
                        b[++t] = s;
                    }
                    s = 1;
                }
            }
            for (int i = 1; i <= x; i++)
                printf("0 ");
            int y = 0;
            for (int i = t; i > 1; i--)
            {
                y += b[i];
                if ((t - i) & 1)
                    ++y;
                printf("%d ", x - y + 1), ++x;
                if ((t - i) & 1)
                    --y;
            }
            printf("\n");
        }
    }
    return 0;
}

