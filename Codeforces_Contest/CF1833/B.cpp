#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N], b[N], ans[N], k;

struct node
{
    int x, y;
    node(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(const node &_) const { return x < _.x; }
} p[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i], p[i] = node(a[i], i);
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b + 1, b + n + 1);
        sort(p + 1, p + n + 1);
        for (int i = 1; i <= n; i++)
            ans[p[i].y] = b[i];
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}

