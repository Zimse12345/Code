#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 2e6 + 10;
int n,ans,pr[N],p[N],pt;

void solve(){
    for(int i=2;i<N;i++){
		if(pr[i]==0)pr[i]=i,p[++pt]=i;
		for(int j=1;j<=pt&&i*p[j]<N;j++){
			pr[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
    }
    
    cin>>n;
    int x=1;
    while(p[x]*p[x]*p[x]*p[x]*p[x]*p[x]*p[x]*p[x]<=n)++x;
    ans=x-1;
    while(p[x]*p[x]<=n)++x;
    --x;
    for(int y=1;y<x;y++){
        while(p[y]*p[y]*p[x]*p[x]>n)--x;
        if(y<x)ans+=x-y;
    }
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
