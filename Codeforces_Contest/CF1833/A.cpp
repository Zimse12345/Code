#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, vis[300][300], ans, n;
char s[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        scanf("%s", s + 1);
        ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (!vis[s[i]][s[i + 1]])
                ++ans, vis[s[i]][s[i + 1]] = 1;
        }
        printf("%d\n", ans);
        for (int i = 'a'; i <= 'z'; i++)
            for (int j = 'a'; j <= 'z'; j++)
                vis[i][j] = 0;
    }
    return 0;
}

