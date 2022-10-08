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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],d[N],lca[4000][4000],c[4000][4000],vis[4000][4000];
vector<int> ch[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
}t[4000][4000];

void dfs(int u,int from,int top,int U){
    lca[u][U]=top;
    for(unsigned i=0;i<ch[u].size();i++){
        int v=ch[u][i];
        if(v==from)continue;
        dfs(v,u,d[top]<d[v]?top:v,U);
    }
    return;
}

void sol(int i,int j){
    if(i==j||vis[i][j]++)return;
    sol(i+1,j),sol(i,j-1);
    t[i][j].x=min(t[i][j].x,min(t[i+1][j].x,t[i][j-1].x));
    t[i][j].y=max(t[i][j].y,max(t[i+1][j].y,t[i][j-1].y));
    return;
}

signed main(){
    n=read(),m=read(),d[1]=1;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=2,f;i<=n;i++)f=read(),ch[f].push_back(i),ch[i].push_back(f),d[i]=d[f]+1;
    for(int i=1;i<=n;i++)dfs(i,0,i,i);
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
        int l=min(a[i],a[j]);
        int r=max(a[i],a[j]);
        t[l][r]=node(a[lca[i][j]],a[lca[i][j]]);
    }
    sol(1,n);
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
        if(t[i][j].x>=i&&t[i][j].y<=j)c[i][j]=1;
        c[i][j]+=c[i][j-1];
    }
    while(m--){
        int L=read(),R=read(),ans=0;
        for(int l=L;l<=R;l++)ans+=c[l][R]-c[l][L-1];
        printf("%d\n",ans);
    }
	return 0;
}
