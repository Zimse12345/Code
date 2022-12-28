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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
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

int n,q,f[N],ans[N];

struct node{
    int x,y,z;
    node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool operator < (const node& _)const{
        return x<_.x;
    }
}a[N],b[N];

struct nd{
    int lmx,rmx,sum,mx;
    nd(int lmx=0,int rmx=0,int sum=0,int mx=0):lmx(lmx),rmx(rmx),sum(sum),mx(mx){}
}t[N*4];

void build(int L,int R,int id){
    t[id]=nd(0,0,R-L+1,0);
    if(L!=R)build(L,M,Lid),build(M+1,R,Rid);
    return;
}

nd merge(nd l,nd r){
    nd res=nd(l.lmx,r.rmx,l.sum+r.sum,max(l.mx,r.mx));
    if(l.lmx==l.sum)res.lmx=l.lmx+r.lmx;
    if(r.rmx==r.sum)res.rmx=r.rmx+l.rmx;
    _max(res.mx,l.rmx+r.lmx);
    return res;
}

void update(int L,int R,int id,int x){
    if(L==R)t[id]=nd(1,1,R-L+1,1);
    else{
        if(x<=M)update(L,M,Lid,x);
        else update(M+1,R,Rid,x);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

signed main(){
    n=read(),q=read();
    for(int i=1;i<=n;i++)f[i]=read(),a[i]=node(f[i],i,0);
    for(int i=1,s,d;i<=q;i++)s=read(),d=read(),b[i]=node(s,d,i);
    sort(a+1,a+n+1);
    sort(b+1,b+q+1);
    build(1,n,1);
    for(int i=q,j=n;i>=1;i--){
        while(j>=1&&a[j].x>b[i].x){
            update(1,n,1,a[j].y);
            --j;
        }
        ans[b[i].z]=(b[i].y>t[1].mx?1:0);
    }
    for(int i=1;i<=q;i++)_write(ans[i]);
    return 0;
}
