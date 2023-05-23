#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N], vis[N], sz, tag;
vector<int> g[N];

void dfs(int u, int from)
{
    if (vis[u])
    {
        tag = 1;
        return;
    }
    ++sz, vis[u] = 1;
    sort(g[u].begin(), g[u].end());
    for (unsigned i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == from)
            continue;
        if (i && g[u][i] == g[u][i - 1])
            continue;
        dfs(v, u);
    }
    return;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        int ans1 = 0, ans2 = 0, p = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            g[i].push_back(a[i]);
            g[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                tag = 0, sz = 0;
                dfs(i, 0);
                if (tag)
                    ++ans1;
                else
                    p = 1;
                ++ans2;
            }
        }
        ans1 += p;
        printf("%d %d\n", ans1, ans2);
        for (int i = 1; i <= n; i++)
            vis[i] = 0, g[i].resize(0);
    }
    return 0;
}

