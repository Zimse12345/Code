#include <bits/stdc++.h>

using namespace std;
const int N = 2000100;

int T, n, c, k, a[N], t[N], popc[N], mn, w[N];
char S[N];

inline int lowbit(int x)
{
    return x & (-x);
}

int main()
{
    cin >> T;
    for (int i = 1; i < N; i++)
        popc[i] = popc[i ^ lowbit(i)] + 1;
    while (T--)
    {
        cin >> n >> c >> k;
        mn = c;
        scanf("%s", S + 1);
        for (int i = 1; i <= n; i++)
            a[i] = S[i] - 'A';
        for (int i = 0; i < (1 << c); i++)
            t[i] = 0;
        for (int i = 0; i < c; i++)
            w[i] = 0;
        for (int i = 1; i < k; i++)
            w[a[i]]++;
        for (int i = k; i <= n; i++)
        {
            w[a[i]]++;
            int x = 0;
            for (int j = 0; j < c; j++)
                if (!w[j])
                    x |= (1 << j);
            w[a[i - k + 1]]--;
            t[x] = 1;
        }
        t[(1 << c) - 1 - (1 << a[n])] = 1;
        for (int i = (1 << c) - 2; i >= 0; i--)
        {
            for (int j = 0; j < c; j++)
                if (!(i & (1 << j)))
                    t[i] |= t[i + (1 << j)];
        }
        for (int i = 0; i < (1 << c); i++)
            if (!t[i])
                mn = min(mn, popc[i]);
        printf("%d\n", mn);
    }
    return 0;
}

