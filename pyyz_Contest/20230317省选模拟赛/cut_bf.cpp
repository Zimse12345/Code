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
//#define int long long
//#define M ((L+R)/2)
#define Lid ch[id][1]
#define Rid ch[id][0]

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

int n,m,a[N],tot,rt,num[N],cnt;

struct node{
    int l,r,L,R,ky,sz,w;
    vector<int> val;
    node(int l=0,int r=0,int L=0,int R=0,int ky=0,int sz=0,int w=0):
    l(l),r(r),L(L),R(R),ky(ky),sz(sz),w(w){}
}t[N];
void update(int id){t[id].sz=t[t[id].l].sz+t[t[id].r].sz+1;return;}

void splitL(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[id].R<x)l=id,splitL(t[id].r,x,t[id].r,r);
    else r=id,splitL(t[id].l,x,l,t[id].l);
    update(id);
    return;
}

void splitR(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[id].L<=x)l=id,splitR(t[id].r,x,t[id].r,r);
    else r=id,splitR(t[id].l,x,l,t[id].l);
    update(id);
    return;
}

void splitsz(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[t[id].l].sz<x)l=id,splitsz(t[id].r,x-t[t[id].l].sz-1,t[id].r,r);
    else r=id,splitsz(t[id].l,x,l,t[id].l);
    update(id);
    return;
}

int merge(int l,int r){
    if(!l||!r)return l|r;
    if(t[l].ky<=t[r].ky){
        t[l].r=merge(t[l].r,r),update(l);
        return l;
    }
    t[r].l=merge(l,t[r].l),update(r);
    return r;
}

void Split(int x,int y,int &L,int &M,int &R){
    splitL(rt,x,L,M),splitR(M,y,M,R);
    int s;
    splitsz(M,1,s,M);
    if(t[s].L<x){
        t[++tot]=node(0,0,t[s].L,x-1,rand(),1,t[s].w);
        vector<int> vl,vr;
        if(!t[s].w){
            int cur=0;
            for(int i=t[s].L;i<x;i++)vl.pb(t[s].val[cur++]);
            for(int i=x;i<=t[s].R;i++)vr.pb(t[s].val[cur++]);
        }
        else{
            int cur=0;
            for(int i=x;i<=t[s].R;i++)vr.pb(t[s].val[cur++]);
            for(int i=t[s].L;i<x;i++)vl.pb(t[s].val[cur++]);
        }
        t[tot].val=vl,t[s].val=vr;
        L=merge(L,tot),t[s].L=x;
    }
    M=merge(s,M);
    splitsz(M,t[M].sz-1,M,s);
    if(y<t[s].R){
        t[++tot]=node(0,0,y+1,t[s].R,rand(),1,t[s].w);
        vector<int> vl,vr;
        if(!t[s].w){
            int cur=0;
            for(int i=t[s].L;i<=y;i++)vl.pb(t[s].val[cur++]);
            for(int i=y+1;i<=t[s].R;i++)vr.pb(t[s].val[cur++]);
        }
        else{
            int cur=0;
            for(int i=y+1;i<=t[s].R;i++)vr.pb(t[s].val[cur++]);
            for(int i=t[s].L;i<=y;i++)vl.pb(t[s].val[cur++]);
        }
        t[s].val=vl,t[tot].val=vr;
        R=merge(tot,R),t[s].R=y;
    }
    M=merge(M,s);
    return;
}

void dfs(int id){
    if(!id)return;
    dfs(t[id].l);
    if(!t[id].w){
        for(int i=0;i<t[id].val.size();i++)num[++cnt]=t[id].val[i];
    }
    else{
        for(int i=t[id].val.size()-1;i>=0;i--)num[++cnt]=t[id].val[i];
    }
    dfs(t[id].r);
    return;
}

signed main(){
    // ifile("cut.in");
    // ofile("cut.out");

    srand(time(0));
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        t[++tot]=node(0,0,i,i,rand(),1,0);
        t[tot].val.pb(a[i]);
        rt=merge(rt,tot);
    }
    while(m--){
        int op=read(),l=read(),r=read(),L,M,R;
        Split(l,r,L,M,R);
        if(op<=2){
            t[++tot]=node(0,0,l,r,rand(),1,op-1);
            cnt=0,dfs(M);
            sort(num+1,num+cnt+1);
            for(int i=1;i<=cnt;i++)t[tot].val.pb(num[i]);
            rt=merge(merge(L,tot),R);
        }
        else{
            cnt=0,dfs(M);
            int f[2]={0,0};
            for(int i=1;i<=cnt;i++){
                if(num[i]&1)_max(f[1],f[0]+1);
                else _max(f[0],f[1]+1);
            }
            _write(max(f[0],f[1]));
            rt=merge(merge(L,M),R);
        }
    }
    return 0;
}
