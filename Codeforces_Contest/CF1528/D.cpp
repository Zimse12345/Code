// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e16,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1024;
int n,m,dis[N][N],d[N],vis[N],to[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node &_)const{return y>_.y;}
};
priority_queue<node> q;

signed main(){
    n=read(),m=read();
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)dis[i][j]=INF;
    for(int i=1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        _min(dis[u][v],w);
    }
    for(int s=0;s<n;s++){
        for(int i=0;i<n;i++)d[i]=INF,vis[i]=0;
        d[s]=0,d[n]=INF;
        while(1){
            int u=n;
            for(int i=0;i<n;i++)if(!vis[i]&&d[i]<d[u])u=i;
            if(u==n)break;
            vis[u]=1;
            for(int v=0;v<n;v++)to[(v+d[u])%n]=dis[u][v];
            for(int i=0,a=0,b=1;i<n*2+2;i++,a++,b++){
                if(a==n)a=0;
                if(b==n)b=0;
                _min(to[b],to[a]+1);
            }
            for(int v=0;v<n;v++)if(d[u]+to[v]<d[v]){
                d[v]=d[u]+to[v];
            }
        }
        for(int i=0;i<n;i++)write_(d[i]);
        pc(10);
    }
    return 0;
}

