/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
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

int n,Llim,Rlim,hd[N],nxt[N],to[N],len[N],ec,ansl,ansr;
int X,vis[N],_n,rt,mncnt,cnt[N],mxdep,mx[N],_mx[N],mxp[N],_mxp[N],que[N],Tag;

struct node{
    int x,y,z;
    node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool operator < (const node& _)const{return y<_.y;}
}ch[N];

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

void findrt(int u,int from){
    cnt[u]=1;
    int mxson=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v]||v==from)continue;
        findrt(v,u);
        cnt[u]+=cnt[v],_max(mxson,cnt[v]);
    }
    _max(mxson,_n-cnt[u]);
    if(mxson<mncnt)mncnt=mxson,rt=u;
    return;
}

void dfs(int u,int from,int dep,int sum){
    if(sum>_mx[dep])_mx[dep]=sum,_mxp[dep]=u;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v]||v==from)continue;
        dfs(v,u,dep+1,sum+(len[i]>=X?1:-1));
    }
    return;
}

void calc(int u){
    int tot=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        ch[++tot]=node(v,cnt[v],len[i]);
    }
    mxdep=0,mx[0]=0,mxp[0]=u;
    sort(ch+1,ch+tot+1);
    for(int i=1,v;i<=tot;i++){
        v=ch[i].x;
        for(int j=1;j<=cnt[v];j++)_mx[j]=-INF;
        dfs(v,0,1,ch[i].z>=X?1:-1);
        int L=1,R=0,t=mxdep;
        for(int j=1;j<=cnt[v];j++){
            while(t>=0&&t+j>=Llim){
                while(L<=R&&mx[que[R]]<mx[t])--R;
                que[++R]=t--;
            }
            while(L<=R&&que[L]+j>Rlim)++L;
            if(L<=R&&_mx[j]+mx[que[L]]>=0)Tag=1,ansl=mxp[que[L]],ansr=_mxp[j];
        }
        for(int j=1;j<=cnt[v];j++){
            if(j>mxdep)mx[j]=-INF;
            if(_mx[j]>mx[j])mx[j]=_mx[j],mxp[j]=_mxp[j];
        }
        mxdep=cnt[v];
    }
    return;
}

void divide(int u){
    vis[u]=1;
    calc(u);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        _n=cnt[v],mncnt=INF;
        findrt(v,0);
        divide(rt);
    }
    return;
}

bool check(int x){
    for(int i=1;i<=n;i++)vis[i]=0;
    X=x;
    _n=n,mncnt=INF;
    findrt(1,0);
    Tag=0;
    divide(rt);
    return Tag;
}

signed main(){
    n=read(),Llim=read(),Rlim=read();
    for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
    int L=0,R=INF,ans=0;
    while(L<=R){
        if(check(M))ans=M,L=M+1;
        else R=M-1;
    }
    printf("%d %d\n",ansl,ansr);
    return 0;
}
