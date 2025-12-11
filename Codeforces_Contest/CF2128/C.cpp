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
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int tag = 1, mn = a[1];

    for (int i = 2; i <= n; i++) {
        int x = a[i] / 2 + 1;

        if (x > mn) {
            tag = 0;
            break;
        }

        mn = min(mn, a[i]);
    }

    if (tag)
        printf("Yes\n");
    else
        printf("No\n");
}
signed main() {
    int _ = 1;
    cin >> _;

    while (_--)
        solve();

    return 0;
}
