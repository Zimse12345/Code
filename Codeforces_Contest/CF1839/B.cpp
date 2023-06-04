#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N], b[N];
vector<int> t[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            t[a[i]].push_back(b[i]);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            sort(t[i].begin(), t[i].end());
            int sz = t[i].size();
            for (int j = sz - 1; j >= max(0, sz - i); j--)
                ans += t[i][j];
            t[i].resize(0);
        }
        cout << ans << '\n';
    }
    return 0;
}

