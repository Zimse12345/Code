#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional>

using namespace std;
const int N = 2100000;

int read()
{
    int x = 0, y = 1;
    char c = getchar();
    while (c < 48 || 57 < c)
    {
        if (c == 45)
            y = -1;
        c = getchar();
    }
    while (47 < c && c < 58)
        x = x * 10 + c - 48, c = getchar();
    return x * y;
}

int T, n, c, k, t[N], popc[N], mn, w[N];
char S[N];

void ins()
{
    int x = 0;
    for (int j = 0; j < c; j++)
        if (!w[j])
            x ^= (1 << j);
    t[x] = 1;
}

int main()
{
    T = read();
    for (int i = 1; i < N; i++)
        popc[i] = popc[i ^ (i & (-i))] + 1;
    while (T--)
    {
        n = read(), c = read(), k = read();
        int C = (1 << c) - 1;
        mn = c;
        scanf("%s", S + 1);
        for (int i = 0; i <= C; i++)
            t[i] = w[i] = 0;
        for (int i = 1; i <= k; i++)
            w[S[i] - 'A']++;
        ins();
        for (int i = k + 1; i <= n; i++)
        {
            w[S[i] - 'A']++;
            w[S[i - k] - 'A']--;
            ins();
        }
        t[C ^ (1 << (S[n] - 'A'))] = 1;
        for (int i = C; i >= 0; i--)
        {
            for (int j = 0; j < c; j++)
                if (!(i & (1 << j)))
                    t[i] |= t[i ^ (1 << j)];
        }
        for (int i = 0; i < (1 << c); i++)
            if (!t[i])
                mn = min(mn, popc[i]);
        printf("%d\n", mn);
    }
    return 0;
}

