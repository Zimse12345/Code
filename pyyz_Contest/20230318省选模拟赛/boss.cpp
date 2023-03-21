/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=100007;

int n,k,a[N],to[N],c[N][11],ans,dis[N],inq[N],pre[N];
struct edge{
    int w,id;
    edge(int w=0,int id=0):w(w),id(id){}
    bool operator < (const edge& _)const{return w>_.w;}
};
priority_queue<edge> g[11][11];
queue<int> q;

void spfa(){
    for(int i=1;i<=k;i++)dis[i]=INF;
    dis[1]=0,q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop(),inq[u]=0;
        for(int i=1;i<=k;i++){
            while(g[u][i].top().id&&to[g[u][i].top().id]!=u)g[u][i].pop();
            if(dis[u]+g[u][i].top().w<dis[i]){
                dis[i]=dis[u]+g[u][i].top().w,pre[i]=u;
                if(!inq[i])q.push(i),inq[i]=1;
            }
        }
    }
    return;
}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=k;i++){
        a[i]=read();
        for(int j=1;j<=k;j++)g[i][j].push(edge(INF,0));
    }
    for(int i=1;i<=n;i++){
        c[i][1]=read();
        ans+=c[i][1],to[i]=1;
        for(int j=2;j<=k;j++){
            c[i][j]=read();
            g[1][j].push(edge(c[i][j]-c[i][1],i));
        }
    }
    n-=a[1];
    while(n--){
        spfa();
        int mn=INF,ed=0;
        for(int i=2;i<=k;i++)if(a[i]&&dis[i]<mn)mn=dis[i],ed=i;
        ans+=dis[ed],--a[ed];
        while(pre[ed]){
            int fr=pre[ed];
            int x=g[fr][ed].top().id;
            to[x]=ed;
            for(int i=1;i<=k;i++)if(i!=ed)g[ed][i].push(edge(c[x][i]-c[x][ed],x));
            ed=fr;
        }
    }
    _write(ans);
    return 0;
}
