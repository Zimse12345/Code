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

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e14+7;
int n,m,s,t,ans,hd[N],h[N],nxt[N],ec=1,d[N],Id[200][200],sum;
struct edge{
    int v,f;
    edge(int v=0,int f=0):v(v),f(f){}
}E[N];
inline void add(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(v,f);return;}
inline void Add(int u,int v,int f){add(u,v,f),add(v,u,0);return;}

queue<int> Q;
bool bfs(){
    for(int i=1;i<=n;i++)d[i]=0;
    d[s]=1,Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
    }
    return d[t];
}

int dfs(int u,int maxf){
    if(u==t||!maxf)return maxf;
    int flow=0;
    for(int i=h[u];i;i=nxt[i]){
        if(d[u]+1==d[E[i].v]){
            int f=dfs(E[i].v,min(maxf,E[i].f));
            flow+=f,maxf-=f,E[i].f-=f,E[i^1].f+=f;
            if(!maxf)break;
        }
        h[u]=nxt[h[u]];
    }
    return flow;
}

void dinic(){
    while(bfs()){
        for(int i=1;i<=n;i++)h[i]=hd[i];
        ans+=dfs(s,INF);
    }
    return;
}

signed main(){
	int a=read(),b=read();
    n=2,s=1,t=2;
    for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)++n,Id[i][j]=n;
    for(int i=1;i<=a;i++){
        for(int j=1,x;j<=b;j++){
            x=read(),sum+=x;
            if((i+j)&1ll){
                Add(s,Id[i][j],x);
                if(i>1)Add(Id[i][j],Id[i-1][j],INF);
                if(i<a)Add(Id[i][j],Id[i+1][j],INF);
                if(j>1)Add(Id[i][j],Id[i][j-1],INF);
                if(j<b)Add(Id[i][j],Id[i][j+1],INF);
            }
            else Add(Id[i][j],t,x);
        }
    }
    dinic();
    printf("%lld\n",sum-ans);
	return 0;
}
