/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-26
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
#define ll long long
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
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
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000000000000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,hd[N],nxt[N],to[N],ec;
int a[N],f[N],ans=INF,Sz[N],Sum[N];

struct node{
    int sz,sum,f,to;
    node(int sz=0,int sum=0,int f=0,int to=0):sz(sz),sum(sum),f(f),to(to){}
    bool operator < (const node& _){
        return sz*_.sum<_.sz*sum;
    }
};

vector<node> p[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dp(int u,int from){
    Sz[u]=1,Sum[u]=a[u];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dp(v,u),Sz[u]+=Sz[v],Sum[u]+=Sum[v];
        p[u].push_back(node(Sz[v],Sum[v],f[v],v));
    }
    sort(p[u].begin(),p[u].end());
    f[u]=a[u];
    int Tim=1;
    for(unsigned i=0;i<p[u].size();i++){
        f[u]+=p[u][i].f+Tim*p[u][i].sum;
        Tim+=p[u][i].sz;
    }
    return;
}

void dfs(int u,int from,node pre){
    // printf("(u=%lld from=%lld) (%lld %lld %lld %lld)\n",u,from,pre.sz,pre.sum,pre.f,pre.to);
    int F=f[u];
    if(from){
        p[u].push_back(pre);
        sort(p[u].begin(),p[u].end());
        F=a[u];
        int Tim=1;
        for(unsigned i=0;i<p[u].size();i++){
            F+=p[u][i].f+Tim*p[u][i].sum;
            Tim+=p[u][i].sz;
        }
        _min(ans,F);
    }
    unsigned sz=p[u].size();
    vector<int> pret(sz),sufs(sz);
    if(sz){
        pret[0]=p[u][0].sz;
        for(unsigned i=1;i<sz;i++)pret[i]=pret[i-1]+p[u][i].sz;
        sufs[sz-1]=p[u][sz-1].sum;
        for(unsigned i=sz-2;i<sz;i--)sufs[i]=sufs[i+1]+p[u][i].sum;
    }
    
    for(unsigned i=0;i<p[u].size();i++){
        int v=p[u][i].to;
        if(!v)continue;
        pre.sz=n-p[u][i].sz,pre.sum=Sum[1]-p[u][i].sum;
        pre.f=F;
        pre.f-=p[u][i].f;
        int pt=1;
        if(i)pt+=pret[i-1];
        pre.f-=pt*p[u][i].sum;
        if(i!=p[u].size()-1)pre.f-=p[u][i].sz*sufs[i+1];
        dfs(v,u,pre);
    }
    return;
}

signed main(){
     ifile("sample.in");
     ofile("sample.out");
    n=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++)a[i]=read();
    dp(1,0);
    ans=f[1];
    dfs(1,0,node(0,0,0,0));
    // for(int i=1;i<=n;i++){
    //     dp(i,0);
    //     _min(ans,f[i]);
    // }
    _write(ans);
    return 0;
}

