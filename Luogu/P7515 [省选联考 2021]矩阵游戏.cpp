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

const int N=1e3+7,M=1e6+7,Mod=998244353,INF=1e18+7;
int T,n,m,a[N][N];
struct edge{int to,w;edge(int to=0,int w=0):to(to),w(w){}};
vector<edge> g[N];
inline void add(int u,int v,int w){g[u].push_back(edge(v,w));}

queue<int> Q;
int vis[N],dis[N],inq[N];
bool spfa(){
    for(int i=0;i<=n+m;i++)dis[i]=INF,vis[i]=0,inq[i]=0;
    while(!Q.empty())Q.pop();
    dis[0]=0,Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        inq[u]=0,vis[u]++;
        if(vis[u]>n+m+1)return false;
        for(int i=0,v,w;i<signed(g[u].size());i++){
            v=g[u][i].to,w=g[u][i].w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                if(!inq[v])Q.push(v),inq[v]=1;
            }
        }
    }
    return true;
}

signed main(){
	T=read();
	while(T--){
        n=read(),m=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)a[i][j]=0;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                a[i][j]=read()-a[i][j-1]-a[i-1][j]-a[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+j)&1){
                    add(i,n+j,a[i][j]);
                    add(n+j,i,1e6-a[i][j]);
                }
                else{
                    add(i,n+j,1e6-a[i][j]);
                    add(n+j,i,a[i][j]);
                }
            }
        }
        for(int i=1;i<=n+m;i++)add(0,i,0);
        if(spfa()){
            printf("YES\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if((i+j)&1)a[i][j]+=dis[i]-dis[j+n];
                    else a[i][j]+=dis[j+n]-dis[i];
                    printf("%lld ",a[i][j]);
                }
                printf("\n");
            }
        }
        else{
            printf("NO\n");
        }
        for(int i=0;i<=n+m;i++)g[i].resize(0);
	}
	return 0;
}
