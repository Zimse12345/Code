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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
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

const int N=1000007,V=1000001;

int n,m,tot,isq[N],ans[N];

struct node{
    int x,y,z,t;
    node(int x=0,int y=0,int z=0,int t=0):x(x),y(y),z(z),t(t){}
    bool operator < (const node& _)const{return x<_.x;}
}p[N];

struct setmenttree{
    int mx[N*4];

    void build(int id,int L,int R){
        mx[id]=-INF;
        if(L!=R)build(Lid,L,M),build(Rid,M+1,R);
        return;
    }

    void update(int id,int L,int R,int x,int y){
        if(L==R)mx[id]=y;
        else{
            if(x<=M)update(Lid,L,M,x,y);
            else update(Rid,M+1,R,x,y);
            mx[id]=max(mx[Lid],mx[Rid]);
        }
        return;
    }

    int query(int id,int L,int R,int l,int r){
        if(l<=L&&r>=R)return mx[id];
        if(r<=M)return query(Lid,L,M,l,r);
        if(l>M)return query(Rid,M+1,R,l,r);
        return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
    }
}a,b;

void cdq(int L,int R){
    if(L<R)cdq(L,M),cdq(M+1,R);
    int pos=L;
    for(int i=M+1;i<=R;i++){
        if(!p[i].t)continue;
        while(pos<=M&&p[pos].x<=p[i].x){
            if(!p[pos].t){
                a.update(1,1,V,p[pos].y,p[pos].x+p[pos].y);
                b.update(1,1,V,p[pos].y,p[pos].x-p[pos].y);
            }
            ++pos;
        }
        _min(ans[p[i].z],p[i].x+p[i].y-a.query(1,1,V,1,p[i].y));
        _min(ans[p[i].z],p[i].x-p[i].y-b.query(1,1,V,p[i].y,V));
    }
    for(int i=L;i<pos;i++)if(!p[i].t){
        a.update(1,1,V,p[i].y,-INF);
        b.update(1,1,V,p[i].y,-INF);
    }
    pos=M;
    for(int i=R;i>M;i--){
        if(!p[i].t)continue;
        while(pos>=L&&p[pos].x>=p[i].x){
            if(!p[pos].t){
                a.update(1,1,V,p[pos].y,-p[pos].x+p[pos].y);
                b.update(1,1,V,p[pos].y,-p[pos].x-p[pos].y);
            }
            --pos;
        }
        _min(ans[p[i].z],-p[i].x+p[i].y-a.query(1,1,V,1,p[i].y));
        _min(ans[p[i].z],-p[i].x-p[i].y-b.query(1,1,V,p[i].y,V));
    }
    for(int i=pos+1;i<=M;i++)if(!p[i].t){
        a.update(1,1,V,p[i].y,-INF);
        b.update(1,1,V,p[i].y,-INF);
    }
    sort(p+L,p+R+1);
    return;
}

signed main(){
    a.build(1,1,V),b.build(1,1,V);
    n=read(),m=read();
    for(int i=1,x,y;i<=n;i++)x=read()+1,y=read()+1,p[++tot]=node(x,y,0,0);
    for(int i=1,t,x,y;i<=m;i++){
        t=read(),x=read()+1,y=read()+1;
        p[++tot]=node(x,y,i,t-1);
        if(t==2)isq[i]=1,ans[i]=INF;
    }
    cdq(1,tot);
    for(int i=1;i<=m;i++)if(isq[i])_write(ans[i]);
    return 0;
}
