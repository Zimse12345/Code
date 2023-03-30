/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
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
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

const int N=200007;

int n,q,hd[N],nxt[N],to[N],len[N],ec,l,r;
int dis[N],dfn[N],Time,ch[N*32][2],tot,sum[N*32];

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

void dfs(int u,int from){
    dfn[u]=++Time;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dis[v]=dis[u]^len[i];
        dfs(v,u);
    }
    return;
}

int X,U,V,fu,fv;
void dfs2(int u,int from,int cnt){
    if(u<=X)++cnt;
    if(cnt==X){
        V=u,fv=from;
        return;
    }
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        if(u==U&&V==0)fu=v;
        dfs2(v,u,cnt);
    }
    return;
}

vector<int> d[2];

void dfs3(int u,int from,int t){
    d[t].pb(dis[u]);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs3(v,u,t);
    }
    return;
}

void ins(int x){
    int p=0;
    for(int i=29;i>=0;i--){
        if(x&(1<<i)){
            if(!ch[p][1])ch[p][1]=++tot;
            p=ch[p][1];
        }
        else{
            if(!ch[p][0])ch[p][0]=++tot;
            p=ch[p][0];
        }
        ++sum[p];
    }
    return;
}

int ck(int x,int R){
    if(R<0)return 0;
    int p=0,res=0;
    for(int i=29;i>=0;i--){
        if(R&(1<<i)){
            if(x&(1<<i)){
                res+=sum[ch[p][1]];
                p=ch[p][0];
            }
            else{
                res+=sum[ch[p][0]];
                p=ch[p][1];
            }
        }
        else{
            if(x&(1<<i))p=ch[p][1];
            else p=ch[p][0];
        }
        if(!p)break;
    }
    return res+sum[p];
}

bool check(int x){
    X=x,U=V=0;
    for(int i=1;i<=x;i++)if(dfn[U]<dfn[i])U=i;
    dfs2(U,0,0);
    if(!V)return false;
    d[0].resize(0),d[1].resize(0);
    dfs3(U,fu,0),dfs3(V,fv,1);
    for(int i=0;i<=tot;i++)ch[i][0]=ch[i][1]=sum[i]=0;
    tot=0;
    for(unsigned i=0;i<d[0].size();i++)ins(d[0][i]);
    for(unsigned i=0;i<d[1].size();i++){
        if(ck(d[1][i],r)-ck(d[1][i],l-1)>0)return true;
    }
    return false;
}

signed main(){
    // ifile("nim.in");
    // ofile("nim.out");

    n=read(),q=read();
    for(int i=1,u,v,w;i<n;i++){
        u=read()+1,v=read()+1,w=read();
        add(u,v,w),add(v,u,w);
    }
    dfs(1,0);
    while(q--){
        l=read(),r=read();
        int tag=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int x=dis[i]^dis[j];
                if(l<=x&&x<=r)tag=1;
            }
        }
        int L=1,R=n,ans=0;
        while(L<=R){
            int M=(L+R)/2;
            if(check(M))ans=M,L=M+1;
            else R=M-1;
        }
        _write(ans);
    }
    return 0;
}
