#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,x[N],y[N],a[N];
map<int,int> vis;

int _abs(int val){
    return val<0?-val:val;
}

bool ck(int u,int v){
    if(v<u)swap(u,v);
    int hs=u*(n+1)+v;
    if(vis[hs])return false;
    vis[hs]=1;
    if(_abs(x[u]-y[u])==1||_abs(x[v]-y[v])==1)return false;
    if(_abs(x[u]-x[v])==1&&_abs(y[u]-y[v])==1)return true;
    return false;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)x[i]=y[i]=0;
        for(int i=1;i<=n*2;i++){
            cin>>a[i];
            if(x[a[i]])y[a[i]]=i;
            else x[a[i]]=i;
        }
        vis.clear();
        int ans=0;
        for(int i=1;i<n*2;i++){
            if(a[i]!=a[i+1]&&ck(a[i],a[i+1]))++ans;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


