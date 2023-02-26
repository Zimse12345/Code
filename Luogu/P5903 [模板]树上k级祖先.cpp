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
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
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

const int N=1000007;

#define ui unsigned int
ui s;

inline ui get(ui x){
    x^=x<<13;
    x^=x>>17;
    x^=x<<5;
    return s=x;
}

int n,q,rt,fa[N],dep[N],son[N],sond[N],pr[N][32],mxbit[N],hd[N];
vector<int> ch[N],p[N];

void dfs(int u){
    dep[u]=dep[fa[u]]+1,sond[u]=1;
    for(unsigned i=0;i<ch[u].size();i++){
        dfs(ch[u][i]);
        if(sond[u]<sond[ch[u][i]]+1){
            sond[u]=sond[ch[u][i]]+1;
            son[u]=ch[u][i];
        }
    }
    return;
}

void dfs2(int u){
    if(son[fa[u]]!=u){
        p[u].resize(sond[u]*2);
        int pos=u;
        while(pos)p[u][sond[u]+dep[pos]-dep[u]]=pos,hd[pos]=u,pos=son[pos];
        pos=fa[u];
        while(pos&&sond[u]+dep[pos]-dep[u]>=0)p[u][sond[u]+dep[pos]-dep[u]]=pos,pos=fa[pos];
    }
    for(unsigned i=0;i<ch[u].size();i++)dfs2(ch[u][i]);
    return;
}

signed main(){
    n=read(),q=read(),scanf("%u",&s);
    for(int i=2;i<N;i++)mxbit[i]=mxbit[i/2]+1;
    for(int i=1;i<=n;i++){
        pr[i][0]=fa[i]=read();
        if(!fa[i])rt=i;
        else ch[fa[i]].pb(i);
    }
    for(int j=1;j<32;j++){
        for(int i=1;i<=n;i++)pr[i][j]=pr[pr[i][j-1]][j-1];
    }
    dfs(rt);
    dfs2(rt);
    ui pre=0;
    unsigned long long Ans=0;
    for(unsigned long long i=1;i<=q;i++){
        int x=(get(s)^pre)%n+1,k=(get(s)^pre)%dep[x];
        if(k)x=pr[x][mxbit[k]],k-=(1<<mxbit[k]);
        pre=p[hd[x]][sond[hd[x]]-dep[hd[x]]+dep[x]-k];
        Ans^=(i*pre);
    }
    printf("%llu\n",Ans);
    return 0;
}
