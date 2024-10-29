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

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1e6 + 10, M = N << 1;
int n,a[N],s[N];

int ave(int l,int r,int t){
    int sum=s[r]-s[l-1];
    if(sum==0)return 0;
    if(t==0)return sum/(r-l+1);
    return (sum-1)/(r-l+1)+1;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
    int tag=0;
    for(int i=2;i<=n;){
        int l=i,r=i;
        while(r<=n&&ave(l,r,0)<ave(1,i-1,1))++r;
        if(r>n)tag=1;
        i=r+1;
    }
    if(tag==0)printf("Yes\n");
    else printf("No\n");
}

signed main(){
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
