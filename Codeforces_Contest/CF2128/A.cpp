#include <bits/stdc++.h>
#define int long long
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int read() {
    int x = 0, f = 1;
    char ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;

        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }

    return x * f;
}
int n, c, a[N];
inline void solve() {
    cin >> n >> c;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    int ans = n;

    for (int i = n, p = 1; i >= 1; i--) {
        if (a[i]*p <= c)
            --ans, p *= 2;
    }

    printf("%lld\n", ans);
}
signed main() {
    int _ = 1;
    cin >> _;

    while (_--)
        solve();

    return 0;
}
