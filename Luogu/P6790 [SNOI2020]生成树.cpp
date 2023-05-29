// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
//#define M ((L+R)/2)
namespace Zimse{const int INF=1.01e9,Mod=998244353;
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

const int N=2.56e6;
int n,m;
long long f[N],g[N],ans;
set<int> E[500010];
queue<int> q;

struct edge{
    int x,y;
    edge(int x=0,int y=0):x(min(x,y)),y(max(x,y)){}
    bool operator < (const edge &_)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};
map<edge,int> Id;
int tot;

signed main(){
    n=read(),m=read(),ans=1;
    for(int i=1,u,v;i<=m;i++){
        u=read(),v=read();
        E[u].insert(v);
        E[v].insert(u);
        edge e=edge(u,v);
        if(!Id[e])Id[e]=++tot,g[tot]=1;
        ++f[Id[e]];
    }
    for(int i=1;i<=n;i++)if(E[i].size()<=2)q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(!E[x].size())continue;
        if(E[x].size()==1){
            int y=*E[x].begin();
            (ans*=f[Id[edge(x,y)]])%=Mod;
            E[x].erase(y),E[y].erase(x);
            if(E[y].size()<=2)q.push(y);
            Id.erase(edge(x,y));
        }
        else{
            int a=*E[x].begin();
            E[x].erase(a),E[a].erase(x);
            int b=*E[x].begin();
            E[x].erase(b),E[b].erase(x);
            int id1=Id[edge(a,x)],id2=Id[edge(b,x)];
            int F=f[id1]*f[id2]%Mod,G=(f[id1]*g[id2]+g[id1]*f[id2])%Mod;
            edge e=edge(a,b);
            if(Id[e]){
                int id=Id[e];
                int _f=(F*g[id]+f[id]*G)%Mod,_g=G*g[id]%Mod;
                f[id]=_f,g[id]=_g;
            }
            else{
                Id[e]=++tot;
                f[tot]=F,g[tot]=G;
                E[a].insert(b),E[b].insert(a);
            }
            if(E[a].size()<=2)q.push(a);
            if(E[b].size()<=2)q.push(b);
            Id.erase(edge(a,x)),Id.erase(edge(b,x));
        }
    }
    printf("%lld\n",ans);
    return 0;
}

