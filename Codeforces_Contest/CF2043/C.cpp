#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
//#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;

int n,a[N],ans[N],cnt;
map<int,int> vis;
void solve(){
    cin>>n;
    int p=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1&&a[i]!=-1)p=i;
    }
    int mn=0,mx=0;
    int mnp=0,mxp=0,mns=0,mxs=0;
    for(int i=p-1,x=0,y=0,s=0;i>=1;i--){
        x=min(x+a[i],0);
        y=max(y+a[i],0);
        s=s+a[i];
        mn=min(mn,x);
        mx=max(mx,y);
        mnp=min(mnp,s);
        mxp=max(mxp,s);
    }
    for(int i=p+1,x=0,y=0,s=0;i<=n;i++){
        x=min(x+a[i],0);
        y=max(y+a[i],0);
        s=s+a[i];
        mn=min(mn,x);
        mx=max(mx,y);
        mns=min(mns,s);
        mxs=max(mxs,s);
    }
    for(int i=mn;i<=mx;i++)if(!vis[i]){
        vis[i]=1,ans[++cnt]=i;
    }
    for(int i=mnp+mns+a[p];i<=mxp+mxs+a[p];i++)if(!vis[i]){
        vis[i]=1,ans[++cnt]=i;
    }
    sort(ans+1,ans+cnt+1);
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
    printf("\n");
    vis.clear();
    cnt=0;
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
