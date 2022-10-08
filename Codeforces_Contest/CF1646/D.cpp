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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],deg[N],ec,ans[N];
int f[N][2],g[N][2];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dp(int u,int from){
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dp(v,u);
        f[u][0]+=f[v][1],g[u][0]+=g[v][1];
        if(f[v][0]>f[v][1]||(f[v][0]==f[v][1]&&g[v][0]<g[v][1]))f[u][1]+=f[v][0],g[u][1]+=g[v][0];
        else f[u][1]+=f[v][1],g[u][1]+=g[v][1];
    }
    ++f[u][0],g[u][0]+=deg[u],++g[u][1];
    return;
}

void dfs(int u,int from,int tag){
    if(tag)ans[u]=1;
    else ans[u]=deg[u];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        if(tag==0)dfs(v,u,1);
        else{
            if(f[v][0]>f[v][1]||(f[v][0]==f[v][1]&&g[v][0]<g[v][1]))dfs(v,u,0);
            else dfs(v,u,1);
        }
    }
    return;
}

signed main(){
	n=read();
    if(n==2){
        printf("%d %d\n%d %d\n",2,2,1,1);
        return 0;
    }
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u),++deg[u],++deg[v];
    dp(1,0);
    if(f[1][0]>f[1][1]||(f[1][0]==f[1][1]&&g[1][0]<g[1][1])){
        printf("%d %d\n",f[1][0],g[1][0]);
        dfs(1,0,0);
    }
    else{
        printf("%d %d\n",f[1][1],g[1][1]);
        dfs(1,0,1);
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
