#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,tag[N];
vector<int> g[N];
char s[N];

void dfs(int u,int from){
    tag[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u),tag[u]=0;
    }
    if(u==1)tag[u]=0;
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)g[i].resize(0);
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%s",s+1);
        dfs(1,0);
        int t=0,t0=0,t1=0,p=0,k=0;
        for(int i=1;i<=n;i++){
            if(tag[i]){
                if(s[i]=='?')++t;
                if(s[i]=='0')++t0;
                if(s[i]=='1')++t1;
            }
            else if(i!=1&&s[i]=='?')++k;
        }
        if(t0==t1&&(k&1)&&s[1]=='?')p^=1;
        if(s[1]=='?'){
            if(t0<t1)s[1]='0';
            else s[1]='1';
            p^=1;
        }
        while(t--){
            if(p==0){
                if(s[1]=='0')++t1;
                else ++t0;
            }
            else{
                if(s[1]=='0')++t0;
                else ++t1;
            }
            p^=1;
        }
        int ans=t0;
        if(s[1]=='0')ans=t1;
        printf("%d\n",ans);
    }
    return 0;
}


