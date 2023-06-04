#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N], f[1000][1000];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        n += 2;
        for (int i = 2; i < n; i++)
        {
            cin >> a[i];
            ++a[i];
        }
        a[1] = 1, a[n] = n;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
                f[i][j] = -n;
        }
        for (int j = 0; j <= n; j++)
            f[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                int premax = -n;
                int B = 0;
                if (i > 1)
                    B = 1;
                for (int j = B; j < i; j++)
                    if (a[j] < a[i])
                        premax = max(premax, f[j][k]);
                for (int j = i; j <= n; j++)
                {
                    if (j > i && a[j] < a[j - 1])
                        break;
                    f[j][k + 1] = max(f[j][k + 1], premax + (j - i + 1));
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            printf("%d ", n - f[n][i]);
        }
        printf("\n");
    }
    return 0;
}

