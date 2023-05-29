#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, ans[N], stk[N], top;
char s[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        scanf("%s", s + 1);
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '(')
                ++x;
            else
                ++y;
            ans[i] = 0;
        }
        if (x != y)
        {
            printf("-1\n");
            continue;
        }
        top = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '(')
                stk[++top] = i;
            else
            {
                if (top)
                    ans[stk[top]] = ans[i] = 1, --top;
            }
        }
        x = 0, y = 0;
        int col = 1;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i])
                x = 1;
            else
                y = 1;
        }
        if (y)
        {
            if (x)
                col = 2;
        }
        if (col == 2)
        {
            int tag = 1;
            for (int i = n, p = 0; i >= 1; i--)
            {
                if (s[i] == '(')
                    ++p;
                else
                    --p;
                if (p < 0)
                {
                    tag = 0;
                    break;
                }
            }
            if (tag)
            {
                for (int i = 1; i <= n; i++)
                    ans[i] = 1;
                col = 1;
            }
        }
        printf("%d\n", col);
        for (int i = 1; i <= n; i++)
        {
            if (!ans[i])
                ans[i] = col;
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

