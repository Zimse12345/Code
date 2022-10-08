/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-
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
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
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
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,m,q,mn[N*4],tag[N*4],ans[N];

struct line{
    int l,r,id;
    line(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
    bool operator < (const line& _)const{return r<_.r;}
}a[N],b[N];

void pushdown(int id){
    if(tag[id]){
        _max(mn[id],tag[id]);
        _max(tag[Lid],tag[id]),_max(tag[Rid],tag[id]);
        tag[id]=0;
    }
    return;
}

void update(int L,int R,int id,int l,int r,int v){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)tag[id]=v,pushdown(id);
    else{
        update(L,M,Lid,l,r,v),update(M+1,R,Rid,l,r,v);
        mn[id]=min(mn[Lid],mn[Rid]);
    }
    return;
}

int query(int L,int R,int id,int l,int r){
    pushdown(id);
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R&&mn[id]>=l)return 0;
    if(L==R)return L;
    int res=query(L,M,Lid,l,r);
    if(res)return res;
    return query(M+1,R,Rid,l,r);
}

signed main(){
    n=read(),m=read();
    for(int i=1,l,r;i<=m;i++)l=read(),r=read(),a[i]=line(l,r,i);
    sort(a+1,a+m+1);
    q=read();
    for(int i=1,l,r;i<=q;i++)l=read(),r=read(),b[i]=line(l,r,i);
    sort(b+1,b+q+1);
    for(int i=1,j=1;i<=q;i++){
        while(j<=m&&a[j].r<=b[i].r)update(1,n,1,a[j].l,a[j].r-1,a[j].l),++j;
        int p=query(1,n,1,b[i].l,b[i].r);
        ans[b[i].id]=p;
    }
    for(int i=1;i<=q;i++)_write(ans[i]);
    return 0;
}
