/********************************
*FileName:
*Author: Zimse
*Data:
*Description:
*Other:
********************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define ll long long
using namespace std;
const int Mod = 998244353;
const int INF = 1000114514;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 1e6 + 7;
int T, n, a[N], ans[N], m, vis[N],b[N],tot;
signed main() {
  T = 1;
  while (T--) {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    ans[++m] = n;
    int v = a[n];
    while (1) {
      int mx = v, pos = 0;
      for (int i = 1; i <= n; i++){
        if ((a[i] | v) > mx) mx = (a[i] | v), pos = i;
        if((a[i]|v)==mx&&pos&&a[i]>a[pos])pos=i;
      }
        
      if (pos)
        ans[++m] = pos, v = mx;
      else
        break;
    }
    for (int i = 1; i <= m; i++) printf("%d ", a[ans[i]]), vis[ans[i]] = 1;
    for (int i = 1; i <= n; i++)
      if (vis[i] == 0) b[++tot]=a[i];
    sort(b+1,b+tot+1);
    for(int i=tot;i>=1;i--)printf("%d ",b[i]);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    printf("\n");
    m = 0;
  }
  return 0;
}
