#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1.01e6;
int T, n, a[N], pos[N];

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        vector<int> v;
        v.push_back(pos[1]), v.push_back(pos[2]), v.push_back(pos[n]);
        sort(v.begin(), v.end());
        printf("%d %d\n", pos[n], v[1]);
    }
    return 0;
}

