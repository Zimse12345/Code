/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int n,m,q,U[N],V[N],X[N],f[N][20],fa[N],fw[N],cnt[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};

struct val{
    int* p;
    int v;
    val(int* p=NULL,int v=0):p(p),v(v){}
}re[N];
int tot=0;

node F(int x){
    if(fa[x]==x)return node(fa[x],0);
    node res=F(fa[x]);
    res.y^=fw[x];
    return res;
}

bool add(int id){
    int x=U[id],y=V[id],t=X[id];
    node a=F(x),b=F(y);
    if(a.x==b.x)return a.y^b.y^t;
    if(cnt[a.x]<cnt[b.x])swap(a,b);
    re[++tot]=val(&fa[b.x],fa[b.x]);
    re[++tot]=val(&cnt[a.x],cnt[a.x]);
    fa[b.x]=a.x,fw[b.x]=(t^a.y^b.y),cnt[a.x]+=cnt[b.x];
    return false;
}

void sol(int l,int r,int L,int R){
    if(r<l)return;
    if(L==R){
        for(int i=l;i<=r;i++)f[i][0]=L+1;
        return;
    }
    int mid=(l+r)/2,tot1=tot;
    for(int i=mid;i<=min(L-1,r);i++)add(i);
    int t=max(mid,L),tot2=tot;
    while(t<=R&&(!add(t)))++t;
    f[mid][0]=t;
    while(tot>tot2){
        *re[tot].p=re[tot].v;
        --tot;
    }
    sol(l,mid-1,L,t-1);
    while(tot>tot1){
        *re[tot].p=re[tot].v;
        --tot;
    }
    for(int i=max(r+1,L);i<t-1;i++)add(i);
    sol(mid+1,r,t-1,R);
    while(tot>tot1){
        *re[tot].p=re[tot].v;
        --tot;
    }
    return;
}

signed main(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
    for(int i=1;i<=m;i++){
        U[i]=read(),X[i]=read(),V[i]=read(),X[i]^=read();
    }
    sol(1,m,1,m);
    for(int i=0;i<20;i++)f[m+1][i]=m+1;
    for(int i=m;i>=1;i--){
    	for(int j=1;j<20;j++)f[i][j]=f[f[i][j-1]][j-1];
	}
    while(q--){
        int l=read(),r=read(),ans=1;
        for(int i=19;i>=0;i--)if(f[l][i]<=r)ans+=(1<<i),l=f[l][i];
        l=f[l][0];
        if(l<=r)_write(-1);
        else _write(ans);
    }
    return 0;
}

