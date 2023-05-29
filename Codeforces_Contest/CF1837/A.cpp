#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, k;

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        if (n % k != 0)
            printf("%d\n%d\n", 1, n);
        else
            printf("%d\n%d %d\n", 2, 1, n - 1);
    }
    return 0;
}

