/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-
*Description:
*Other:
********************************/

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
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e3+7;

int n,m,a,b,fa[N],hd[N],nxt[N],to[N],len[N],dis[N],vis[N],p[N][100],ec;
struct edge{
    int u,v;
    edge(int u,int v):u(u),v(v){}
};
vector<edge> e1,e2;

int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

struct node{
    int pos,dis;
    node(int pos=0,int dis=0):pos(pos),dis(dis){}
    bool operator < (const node& _)const{return dis>_.dis;}
};
priority_queue<node> q;

signed main(){
    n=read(),m=read(),a=read(),b=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        if(w==a)e1.pb(edge(u,v));
        else e2.pb(edge(u,v));
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    for(unsigned i=0;i<e1.size();i++){
        int x=e1[i].u,y=e1[i].v;
        add(x,y,a),add(y,x,a);
        x=F(x),y=F(y);
        if(x!=y)fa[y]=x;
    }
    for(unsigned i=0;i<e2.size();i++){
        int x=e2[i].u,y=e2[i].v;
        if(F(x)!=F(y))add(x,y,b),add(y,x,b);
    }
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[1]=0,p[1][F(1)]=1;
    q.push(node(1,0));
    while(!q.empty()){
        int u=q.top().pos;
        q.pop();
        if(vis[u]++)continue;
        for(int i=hd[u],v;i;i=nxt[i]){
            v=to[i];
            if(p[u][F(v)]&&len[i]==b)continue;
            if(dis[u]+len[i]<dis[v]){
                dis[v]=dis[u]+len[i];
                for(int j=1;j<=n;j++)p[v][j]=p[u][j];
                p[v][F(v)]=1;
                q.push(node(v,dis[v]));
            }
        }
    }
    for(int i=1;i<=n;i++)write_(dis[i]);
    pc(10);
    return 0;
}
