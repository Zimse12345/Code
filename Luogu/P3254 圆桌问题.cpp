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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,s,t,ans,hd[N],h[N],nxt[N],d[N],ec=1;
int a,b,r[N],c[N],e[2000][2000];
struct edge{
    int v,f;
    edge(int v=0,int f=0):v(v),f(f){}
}E[N];
void add(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(v,f);return;}
void Add(int u,int v,int f){add(u,v,f),add(v,u,0);return;}

queue<int> Q;
bool bfs(){
    for(int i=1;i<=n;i++)d[i]=0;
    Q.push(s),d[s]=1;
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
            maxf-=f,flow+=f,E[i].f-=f,E[i^1].f+=f;
            if(!maxf)break;
        }
        h[u]=nxt[i];
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
	a=read(),b=read();
    int sum=0;
    n=a+b+2,s=n-1,t=n;
    for(int i=1;i<=a;i++){
        r[i]=read();
        sum+=r[i];
        Add(s,i,r[i]);
    }
    for(int i=1;i<=b;i++){
        c[i]=read();
        Add(i+a,t,c[i]);
    }
    for(int i=1;i<=a;i++)for(int j=1;j<=b;j++){
        Add(i,j+a,1);
        e[i][j]=ec-1;
    }
    dinic();
    if(ans!=sum){
        printf("0\n");
    }
    else{
        printf("1\n");
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++)if(E[e[i][j]].f==0){
                printf("%d ",j);
            }
            printf("\n");
        }
    }
	return 0;
}
