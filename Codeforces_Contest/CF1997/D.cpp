#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],fa[N];
vector<int> g[N];

bool dfs(int u,int x){
    int t=0;
    if(a[u]-x<0)t=x-a[u];
    if(t>1000000000)return false;
    if(!g[u].size()&&a[u]-x<0)return false;
    for(unsigned i=0;i<g[u].size();i++)if(!dfs(g[u][i],t+x))return false;
    return true;
}

bool ck(int x){
    a[1]=-x;
    return dfs(1,0);
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],g[i].resize(0);
        for(int i=2;i<=n;i++)cin>>fa[i],g[fa[i]].push_back(i);
        int rt=a[1],L=1,R=1000000000,res=0;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M))res=M,L=M+1;
            else R=M-1;
        }
        printf("%lld\n",rt+res);
    }
    return 0;
}


