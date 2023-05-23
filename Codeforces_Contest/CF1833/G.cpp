#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, ans[N], cnt, sz[N];
struct edge
{
    int to, id;
    edge(int to = 0, int id = 0) : to(to), id(id) {}
};
vector<edge> g[N];

void dfs(int u, int from, int fid)
{
    sz[u] = 1;
    for (unsigned i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i].to;
        if (v == from)
            continue;
        dfs(v, u, g[u][i].id), sz[u] += sz[v];
    }
    if (sz[u] > 3)
    {
        cnt = -1;
        return;
    }
    if (sz[u] == 3)
    {
        sz[u] = 0;
        if (fid)
            ans[++cnt] = fid;
    }
    return;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        cnt = 0;
        for (int i = 1, u, v; i < n; i++)
        {
            cin >> u >> v;
            g[u].push_back(edge(v, i));
            g[v].push_back(edge(u, i));
        }
        dfs(1, 0, 0);
        for (int i = 1; i <= n; i++)
            g[i].resize(0);
        if (sz[1])
            cnt = -1;
        printf("%d\n", cnt);
        if (cnt >= 0)
        {
            sort(ans + 1, ans + cnt + 1);
            for (int i = 1; i <= cnt; i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}

