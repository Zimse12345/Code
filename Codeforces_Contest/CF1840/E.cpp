#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, t, q, tag[N], p[N], v;
char s[2][N];

void calc(int pos, int t)
{
    if (s[0][pos] != s[1][pos])
        v += t;
    return;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        scanf("%s", s[0] + 1);
        scanf("%s", s[1] + 1);
        n = strlen(s[0] + 1), v = 0;
        for (int i = 1; i <= n; i++)
            tag[i] = 0, calc(i, 1);
        cin >> t >> q;
        for (int i = 1, ty, pos1, id1, pos2, id2; i <= q; i++)
        {
            if (i > t && p[i - t])
            {
                pos1 = p[i - t];
                tag[pos1]--;
                if (!tag[pos1])
                    calc(pos1, 1);
            }
            cin >> ty;
            p[i] = 0;
            if (ty == 1)
            {
                cin >> pos1;
                p[i] = pos1;
                if (!tag[pos1])
                    calc(pos1, -1);
                tag[pos1]++;
            }
            if (ty == 2)
            {
                cin >> id1 >> pos1 >> id2 >> pos2;
                --id1, --id2;
                if (!tag[pos1])
                    calc(pos1, -1);
                if (!tag[pos2])
                    calc(pos2, -1);
                swap(s[id1][pos1], s[id2][pos2]);
                if (!tag[pos1])
                    calc(pos1, 1);
                if (!tag[pos2])
                    calc(pos2, 1);
            }
            if (ty == 3)
            {
                if (v)
                    printf("No\n");
                else
                    printf("Yes\n");
            }
        }
    }
    return 0;
}

