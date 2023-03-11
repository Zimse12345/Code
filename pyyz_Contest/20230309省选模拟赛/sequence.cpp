/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

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
#define inv fpow
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1600007,V=1048575;

int n,q,a[N];

struct node{
    int mx,a,o,ta,to;
    node(int mx=0,int a=0,int o=0,int ta=0,int to=0):mx(mx),a(a),o(o),ta(ta),to(to){};
}t[N];

node merge(node l,node r){
    return node(max(l.mx,r.mx),l.a&r.a,l.o|r.o,V,0);
}

void build(int id,int L,int R){
    if(L==R)t[id]=node(a[L],a[L],a[L],V,0);
    else build(Lid,L,M),build(Rid,M+1,R),t[id]=merge(t[Lid],t[Rid]);
    return;
}

void pushdown(int id){
    t[id].mx&=t[id].ta,t[id].mx|=t[id].to;
    t[id].a&=t[id].ta,t[id].a|=t[id].to;
    t[id].o&=t[id].ta,t[id].o|=t[id].to;
    t[Lid].ta&=t[id].ta,t[Lid].to&=t[id].ta,t[Lid].to|=t[id].to;
    t[Rid].ta&=t[id].ta,t[Rid].to&=t[id].ta,t[Rid].to|=t[id].to;
    t[id].ta=V,t[id].to=0;
    return;
}

void update(int id,int L,int R,int l,int r,int x,int typ){
    pushdown(id);
    if(l<=L&&r>=R){
        int v=(V^t[id].o)|t[id].a;
        if(typ){//OR
            if((v&x)==x)t[id].to|=x;
            else update(Lid,L,M,l,r,x,typ),update(Rid,M+1,R,l,r,x,typ),t[id]=merge(t[Lid],t[Rid]);
        }
        else{//AND
            if((v&(V^x))==(V^x))t[id].ta&=x,t[id].to&=x;
            else update(Lid,L,M,l,r,x,typ),update(Rid,M+1,R,l,r,x,typ),t[id]=merge(t[Lid],t[Rid]);
        }
        pushdown(id);
    }
    else if(r<L||R<l)return;
    else{
        update(Lid,L,M,l,r,x,typ),update(Rid,M+1,R,l,r,x,typ);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    pushdown(id);
    if(l<=L&&r>=R)return t[id].mx;
    if(r<L||R<l)return 0;
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    n=read(),q=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,1,n);
    while(q--){
        int typ=read(),l=read(),r=read();
        if(typ<=2)update(1,1,n,l,r,read(),typ-1);
        else _write(query(1,1,n,l,r));
    }
    return 0;
}
