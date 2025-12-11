#include <bits/stdc++.h>
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
int n, k, a[N], L, R, b[N];

bool ck(int x) {
    for (int i = 1, s = 0, mn = 1e9, p = 0; i <= n; i++) {
        if (i - k >= 0) {
            if (b[i - k] < mn)
                mn = b[i - k], p = i - k;
        }

        if (a[i] >= x)
            ++s;
        else --s;

        b[i] = s;

        if (s - mn >= 0) {
            L = p + 1, R = i;
            return true;
        }
    }

    return false;
}

inline void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 1, r = n, ans = 0, ansl = 0, ansr = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (ck(mid))
            ans = mid, ansl = L, ansr = R, l = mid + 1;
        else
            r = mid - 1;
    }

    printf("%d %d %d\n", ans, ansl, ansr);

}
signed main() {
    int _ = 1;
    cin >> _;

    while (_--)
        solve();

    return 0;
}
