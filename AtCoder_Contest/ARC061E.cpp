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

const int N=1e6+7;

int n,m,cnt,dis[N],vis[N],ans=INF;

struct edge{
    int to,len;
    edge(int to=0,int len=0):to(to),len(len){}
};
vector<edge> g[N];

struct node{
    int pos,dis;
    node(int pos=0,int dis=0):pos(pos),dis(dis){}
    bool operator < (const node& _)const{return dis>_.dis;}
};
priority_queue<node> q;

map<int,int> id[N];
int tot,mid[N];

void link(int u,int v,int w){
    g[u].pb(edge(v,w));
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1,u,v,c;i<=m;i++){
        u=read(),v=read(),c=read();
        if(!id[u][c])id[u][c]=++tot;
        if(!id[v][c])id[v][c]=++tot;
        link(id[u][c],id[v][c],0),link(id[v][c],id[u][c],0);
    }
    for(int i=1;i<=n;i++){
        mid[i]=++tot;
        for(map<int,int>::iterator it=id[i].begin();it!=id[i].end();it++){
            link(it->second,mid[i],0);
            link(mid[i],it->second,1);
        }
    }
    for(int i=1;i<=tot;i++)dis[i]=INF;
    dis[mid[1]]=0,q.push(node(mid[1],0));
    while(!q.empty()){
        int u=q.top().pos;
        q.pop();
        if(vis[u]++)continue;
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i].to,d=dis[u]+g[u][i].len;
            if(d<dis[v])dis[v]=d,q.push(node(v,d));
        }
    }
    if(dis[mid[n]]==INF)dis[mid[n]]=-1;
    _write(dis[mid[n]]);
    return 0;
}
