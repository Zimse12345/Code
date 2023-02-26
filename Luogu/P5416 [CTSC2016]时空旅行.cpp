/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

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
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000000000000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=500007;

int n,m,Id[N],dfn[N],_dfn[N],sz[N],Time,top;
vector<int> g[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
}p[N];
vector<node> del[N],t[N*4];
node stk[N];

void Add(int id,int L,int R,int l,int r,int x){
    if(l<=L&&r>=R)t[id].pb(p[x]);
    else if(r<L||R<l)return;
    else Add(Lid,L,M,l,r,x),Add(Rid,M+1,R,l,r,x);
    return;
}

double Slope(node a,node b){
    return double(b.y-a.y)/double(b.x-a.x);
}

void Init(int id,int L,int R){
    if(L!=R)Init(Lid,L,M),Init(Rid,M+1,R);
    sort(t[id].begin(),t[id].end());
    for(unsigned i=0;i<t[id].size();i++){
        int x=t[id][i].x,y=t[id][i].y;
        while(i+1<t[id].size()&&t[id][i+1].x==t[id][i].x)++i,_min(y,t[id][i].y);
        y+=x*x,x*=2;
        while(top>1&&Slope(stk[top-1],stk[top])>=Slope(stk[top],node(x,y)))--top;
        stk[++top]=node(x,y);
    }
    t[id].resize(0);
    for(int i=1;i<=top;i++)t[id].pb(stk[i]);
    top=0;
    return;
}

int query(int id,int L,int R,int x,int v){
    int res=INF,sz=t[id].size();
    int l=0,r=sz-2,mx=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(double(v)>=Slope(t[id][mid],t[id][mid+1]))mx=mid+1,l=mid+1;
        else r=mid-1;
    }
    if(mx<sz)_min(res,t[id][mx].y-v*t[id][mx].x+v*v);
    if(L!=R){
        if(x<=M)_min(res,query(Lid,L,M,x,v));
        else _min(res,query(Rid,M+1,R,x,v));
    }
    return res;
}

void dfs(int u,int from){
    dfn[u]=++Time,_dfn[Time]=u,sz[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v,u),sz[u]+=sz[v];
    }
    if(Id[u]<0)del[-Id[u]].pb(node(dfn[u],dfn[u]+sz[u]-1));
    else{
        int L=dfn[u],R=L+sz[u]-1,id=Id[u];
        sort(del[id].begin(),del[id].end());
        int p=L;
        for(unsigned i=0;i<del[id].size();i++){
            Add(1,1,n,p,del[id][i].x-1,id),p=del[id][i].y+1;
        }
        Add(1,1,n,p,R,id);
    }
    return;
}

signed main(){
    n=read(),m=read();
    p[0]=node(0,read());
    for(int i=1,ty,fr,id,x,c;i<n;i++){
        ty=read(),fr=read(),id=read();
        g[fr].pb(i);
        if(ty)Id[i]=-id;
        else{
            x=read(),read(),read(),c=read();
            Id[i]=id,p[id]=node(x,c);
        }
    }
    dfs(0,0);
    Init(1,1,n);
    for(int i=1,u,x;i<=m;i++){
        u=read(),x=read();
        _write(query(1,1,n,dfn[u],x));
    }
    return 0;
}
