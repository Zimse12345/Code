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
// #define int long long
#define M ((L+R)/2)
#define Lid ch[id][0]
#define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
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

const int N=1000007;

int n,b[N],hd[N],nxt[N],to[N],ec,ans;
int _b[N],val[N],ival[N],num;
int ch[N*12][2],rt[N],tot;
int sumf[N*12],_sumf[N*12],mu[N*12];
map<int,int> mp;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

inline void ins(signed &id,int L,int R,int x){
    id=++tot;
    sumf[id]=-val[x],_sumf[id]=1,mu[id]=1;
    if(L!=R){
        if(x<=M)ins(Lid,L,M,x);
        else ins(Rid,M+1,R,x);
    }
    return;
}

inline void pushdown(int id){
    if(!id)return;
    if(mu[id]!=1){
        if(Lid)mu[Lid]=1ll*mu[Lid]*mu[id]%Mod;
        if(Rid)mu[Rid]=1ll*mu[Rid]*mu[id]%Mod;
        sumf[id]=1ll*sumf[id]*mu[id]%Mod;
        _sumf[id]=1ll*_sumf[id]*mu[id]%Mod;
        mu[id]=1;
    }
    return;
}

int Sum=0;
int merge(signed id,signed _id,int L,int R,int s,int _s){
    pushdown(id),pushdown(_id);
    if(!id&&!_id)return 0;
    if(!_id){
        mu[id]=(Sum+_s)%Mod;
        pushdown(id);
        return id;
    }
    if(!id){
        mu[_id]=s;
        pushdown(_id);
        return _id;
    }
    if(L==R){
        sumf[id]=(1ll*sumf[id]*(1ll*Sum+_s+_sumf[_id])+1ll*sumf[_id]*s)%Mod;
        _sumf[id]=-1ll*sumf[id]*ival[L]%Mod;
        pushdown(id);
        return id;
    }
    pushdown(Rid),pushdown(ch[_id][1]);
    Lid=merge(Lid,ch[_id][0],L,M,(s+_sumf[Rid])%Mod,(_s+_sumf[ch[_id][1]])%Mod);
    Rid=merge(Rid,ch[_id][1],M+1,R,s,_s);
    sumf[id]=(sumf[Lid]+sumf[Rid])%Mod;
    _sumf[id]=(_sumf[Lid]+_sumf[Rid])%Mod;
    return id;
}

void dfs(int u,int from){
    ins(rt[u],1,num,b[u]);
    for(int I=hd[u],v;I;I=nxt[I]){
        v=to[I];
        if(v==from)continue;
        dfs(v,u);
        pushdown(rt[v]),Sum=sumf[rt[v]];
        merge(rt[u],rt[v],1,num,0,0);
    }
    pushdown(rt[u]);
    return;
}

signed main(){
    // ifile("b.in");
    // ofile("b.out");

    n=read();
    for(int i=1;i<=n;i++)_b[i]=b[i]=read();
    sort(_b+1,_b+n+1),_b[0]=-1;
    
    for(int i=1;i<=n;i++)if(_b[i]!=_b[i-1]){
        val[++num]=_b[i],ival[num]=inv(val[num]);
        mp[_b[i]]=num;
    }
    for(int i=1;i<=n;i++)b[i]=mp[b[i]];
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs(1,0);
    ans=sumf[rt[1]];
    if(n&1)ans=-ans;
    addmod(ans,Mod);
    _write(ans);
    return 0;
}
