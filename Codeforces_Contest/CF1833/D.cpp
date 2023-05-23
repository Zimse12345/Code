#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N], b[N], ans[N];

void check()
{
    for (int i = 1; i <= n; i++)
    {
        if (b[i] < ans[i])
            return;
        if (b[i] > ans[i])
        {
            for (int j = 1; j <= n; j++)
                ans[j] = b[j];
            return;
        }
    }
    return;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        int t = n;
        if (a[1] == n)
            t = n - 1;
        for (int i = 1; i <= n; i++)
            if (a[i + 1] == t)
            {
                for (int j = 1; j <= i; j++)
                {
                    int cur = 0;
                    for (int k = i + 1; k <= n; k++)
                        b[++cur] = a[k];
                    for (int k = i; k >= j; k--)
                        b[++cur] = a[k];
                    for (int k = 1; k < j; k++)
                        b[++cur] = a[k];
                    check();
                }
            }
        if (a[n] == n || a[n] == n - 1)
        {
            for (int j = 1; j <= n; j++)
            {
                int cur = 0;
                for (int k = n; k >= j; k--)
                    b[++cur] = a[k];
                for (int k = 1; k < j; k++)
                    b[++cur] = a[k];
                check();
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]), ans[i] = 0;
        printf("\n");
    }
    return 0;
}

