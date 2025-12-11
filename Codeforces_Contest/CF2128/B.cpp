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

    int l = 1, r = n, t = 0;

    while (l < r) {
        if (t) {
            if (a[l] < a[r])
                printf("LR");
            else
                printf("RL");
        } else {
            if (a[l] < a[r])
                printf("RL");
            else
                printf("LR");
        }

        t ^= 1;
        ++l, --r;
    }

    if (l == r)
        printf("L");

    printf("\n");
}
signed main() {
    int _ = 1;
    cin >> _;

    while (_--)
        solve();

    return 0;
}
