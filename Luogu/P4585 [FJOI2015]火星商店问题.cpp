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

const int N=1000007;

int n,m,val[N],Time,isq[N],num[N],lim[N],ans[N];
int ch[N*32][2],tot,pre[N*32];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> upt[N],qry[N];

void update(int id,int L,int R,int x,int y){
    upt[id].pb(node(Time,y));
    if(L==R)return;
    else if(x<=M)update(Lid,L,M,x,y);
    else update(Rid,M+1,R,x,y);
    return;
}

void query(int id,int L,int R,int l,int r,int x){
    if(l<=L&&r>=R)qry[id].pb(node(Time,x));
    else if(r<L||R<l)return;
    else query(Lid,L,M,l,r,x),query(Rid,M+1,R,l,r,x);
}

void ins(node x){
    if(!x.x)x.x=INF;
    int p=0;
    for(int i=24;i>=0;i--){
        if(x.y&(1<<i)){
            if(!ch[p][1])ch[p][1]=++tot,pre[tot]=0;
            p=ch[p][1];
        }
        else{
            if(!ch[p][0])ch[p][0]=++tot,pre[tot]=0;
            p=ch[p][0];
        }
        _max(pre[p],x.x);
    }
    return;
}

int qmx(node x){
    x.x-=lim[x.y]-1;
    int res=0,p=0;
    for(int i=24;i>=0;i--){
        if(num[x.y]&(1<<i)){
            if(ch[p][0]&&pre[ch[p][0]]>=x.x)p=ch[p][0],res|=(1<<i);
            else p=ch[p][1];
        }
        else{
            if(ch[p][1]&&pre[ch[p][1]]>=x.x)p=ch[p][1],res|=(1<<i);
            else p=ch[p][0];
        }
        if(pre[p]<x.x||p==0)return 0;
    }
    return res;
}

void sol(int id,int L,int R){
    unsigned pos=0;
    for(unsigned i=0;i<qry[id].size();i++){
        while(pos<upt[id].size()&&upt[id][pos].x<=qry[id][i].x){
            ins(upt[id][pos]);
            ++pos;
        }
        _max(ans[qry[id][i].y],qmx(qry[id][i]));
    }
    for(int i=0;i<=tot;i++)ch[i][0]=ch[i][1]=0;
    tot=0;
    if(L!=R)sol(Lid,L,M),sol(Rid,M+1,R);
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        val[i]=read();
        update(1,1,n,i,val[i]);
    }
    for(int i=1;i<=m;i++){
        int ty=read();
        if(!ty){
            int x=read(),y=read();
            ++Time,update(1,1,n,x,y);
        }
        else{
            int l=read(),r=read(),x=read(),d=read();
            isq[i]=1,num[i]=x,lim[i]=d;
            query(1,1,n,l,r,i);
        }
    }
    sol(1,1,n);
    for(int i=1;i<=m;i++)if(isq[i])_write(ans[i]);
    return 0;
}
