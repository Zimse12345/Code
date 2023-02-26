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
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
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

const int N=100007;

int n,m,q,pr[N],ct[N];

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}a[N];
vector<edge> t[N*4];

int F(int x){
    if(pr[x]!=x)pr[x]=F(pr[x]);
    return pr[x];
}

bool link(edge x){
    int u=F(x.u),v=F(x.v);
    if(u!=v){
        if(ct[u]<ct[v])swap(u,v);
        pr[v]=u,ct[u]+=ct[v];
        return true;
    }
    return false;
}

inline void re(int x){
    pr[x]=x,ct[x]=1;
    return;
}

vector<edge> merge(const vector<edge>& x,const vector<edge>& y){
    vector<edge> res;
    unsigned i=0,j=0;
    while(i<x.size()||j<y.size()){
        if(i<x.size()&&(j>=y.size()||x[i].w<=y[j].w)){
            if(link(x[i]))res.pb(x[i]);
            ++i;
        }
        else{
            if(link(y[j]))res.pb(y[j]);
            ++j;
        }
    }
    for(unsigned k=0;k<res.size();k++)re(res[k].u),re(res[k].v);
    return res;
}

void build(int id,int L,int R){
    if(L==R)t[id].pb(a[L]);
    else build(Lid,L,M),build(Rid,M+1,R),t[id]=merge(t[Lid],t[Rid]);
    return;
}

vector<edge> query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return t[id];
    if(r<=M)return query(Lid,L,M,l,r);
    if(l>M)return query(Rid,M+1,R,l,r);
    return merge(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)re(i);
    for(int i=1;i<=m;i++)a[i].u=read(),a[i].v=read(),a[i].w=read();
    build(1,1,m);
    while(q--){
        int l=read(),r=read();
        vector<edge> ans=query(1,1,m,l,r);
        int sum=0;
        for(unsigned i=0;i<ans.size();i++)sum+=ans[i].w;
        _write(sum);
    }
    return 0;
}
