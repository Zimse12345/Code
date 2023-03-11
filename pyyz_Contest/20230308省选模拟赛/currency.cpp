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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

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

const int N=1000007;

int n,q,T,col[N],nx[N],mx[N],f[N],fl[N],fr[N];
set<int> pos[N],hd;

void update(int id,int L,int R,int x,int y){
    if(L==R)mx[id]=y;
    else{
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
        mx[id]=max(mx[Lid],mx[Rid]);
    }
    return;
}

int query(int id,int L,int R,int x){
    if(x<L||mx[id]<=x)return 0;
    if(L==R)return L;
    int l=query(Lid,L,M,x);
    return l?l:query(Rid,M+1,R,x);
}

void update(int x,int y){
    if(y<nx[x])nx[x]=y,update(1,1,n,x,y);
    int L=fl[x],R=fr[x];
    if(L)while(L<=R){
        int p=query(1,1,n,L);
        // printf("[%d %d %d %d]\n",L,R,p,nx[p]);
        for(int i=L;i<nx[p];i++)f[i]=p;//printf("f[%d]=%d\n",i,p);
        fl[p]=L,fr[p]=nx[p]-1,L=nx[p];
    }
    return;
}

signed main(){
	// ifile("currency.in");
	// ofile("currency.out");
	
    n=read(),q=read(),T=read();
    fl[1]=1,fr[1]=n;
    for(int i=1;i<=n;i++){
        col[i]=i,f[i]=1;
        update(1,1,n,i,n+1),nx[i]=n+1;
        pos[i].insert(i),pos[i].insert(-INF),pos[i].insert(INF);
        hd.insert(-i);
    }
    for(int i=1,ans=0;i<=q;i++){
        int u=col[(read()+T*ans-1)%n+1];
        int v=col[(read()+T*ans-1)%n+1];
        if(u==v){
            _write(ans);
            continue;
        }
        set<int>::iterator iu=pos[u].begin(),iv=pos[v].begin();
        ++iu,++iv;
        if(*iu<*iv)hd.erase(-*iv);
        else hd.erase(-*iu);
        if(pos[u].size()<pos[v].size())swap(u,v);
        for(set<int>::iterator it=pos[v].begin();it!=pos[v].end();it++){
            if(*it==-INF||*it==INF)continue;
            set<int>::iterator pre=pos[u].lower_bound(*it),nxt=pre--;
            if(*pre!=-INF)update(*pre,*it);
            if(*nxt!=INF)update(*it,*nxt);
            pos[u].insert(*it),col[*it]=u;
        }
        pos[v].clear();
        ans=n;
        for(int i=-*hd.begin();i<=n;i++)_min(ans,i-f[i]+1);
        _write(ans);
    }
    return 0;
}
