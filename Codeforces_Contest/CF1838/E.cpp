#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1.01e6, Mod = 1e9 + 7;
int T, n, m, k, a[N];

#define inv fpow
inline int fpow(long long x, int y = Mod - 2)
{
    int z = 1;
    while (y)
    {
        if (y & 1)
            z =
                x * z % Mod;
        x = x * x % Mod, y /= 2;
    }
    return z;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = fpow(k, m);
        int c = 1;
        for (int i = 0; i < n; i++)
        {
            ans = (ans - c * fpow(k - 1, m - i)) % Mod;
            c = c * (m - i) % Mod * inv(i + 1) % Mod;
        }
        ans = (ans + Mod) % Mod;
        printf("%lld\n", ans);
    }
    return 0;
}

