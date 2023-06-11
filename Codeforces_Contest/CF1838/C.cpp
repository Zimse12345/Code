#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e3;
int T, n, m, ans[N][N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        int cur = 0;
        for (int i = 1; i <= n; i += 2)
        {
            for (int j = 1; j <= m; j++)
                ans[i][j] = ++cur;
        }
        for (int i = 2; i <= n; i += 2)
        {
            for (int j = 1; j <= m; j++)
                ans[i][j] = ++cur;
        }
        if (n == 4)
        {
            cur = 0;
            for (int j = 1; j <= m; j++)
            {
                for (int i = 1; i <= n; i++)
                    ans[i][j] = ++cur;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}

