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
int n, a[N];
inline void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;

    for (int i = 2; i < n; i++) {
        if (a[i] > a[i + 1])
            ans += i * (n - i + 1);
        else
            ans += i;
    }

    if (a[1] > a[2])
        ans += n;
    else
        ans += 1;

    ans += n;
    printf("%lld\n", ans);

}
signed main() {
    int _ = 1;
    cin >> _;

    while (_--)
        solve();

    return 0;
}
