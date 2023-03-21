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
#define Lid ch[id][0]
#define Rid ch[id][1]

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

const int N=2000007;

int n,m,a[N],tot,rt,num[N],cnt;

struct F{int s[2][2];}f[N*16],emp;
int ch[N*16][2],Sz[N*16],Tot;
stack<int> rbs;

inline int NewId(){
    if(!rbs.empty()){
        int id=rbs.top();
        Lid=Rid=Sz[id]=0;
        f[id].s[0][0]=f[id].s[0][1]=f[id].s[1][0]=f[id].s[1][1]=0;
        rbs.pop();
        return id;
    }
    return ++Tot;
}

F pushup(F l,F r){
    F res;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++){
        res.s[i][j]=max(l.s[i][j],r.s[i][j]);
        if(l.s[i][j]==0)--l.s[i][j];
        if(r.s[i][j]==0)--r.s[i][j];
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++){
        _max(res.s[i][j],max(l.s[i][0]+r.s[1][j],l.s[i][1]+r.s[0][j]));
    }
    return res;
}

void ins(int &id,int L,int R,int x){
    if(!id)id=NewId();
    ++Sz[id];
    if(L==R)f[id].s[x&1][x&1]=1;
    else{
        int M=(L+R)/2;
        if(x<=M)ins(Lid,L,M,x);
        else ins(Rid,M+1,R,x);
        f[id]=pushup(f[Lid],f[Rid]);
    }
    return;
}

int Merge(int lid,int rid,int L,int R){
    if(!lid||!rid)return lid|rid;
    int id=NewId(),M=(L+R)/2;
    Lid=Merge(ch[lid][0],ch[rid][0],L,M);
    Rid=Merge(ch[lid][1],ch[rid][1],M+1,R);
    rbs.push(lid),rbs.push(rid);
    f[id]=pushup(f[Lid],f[Rid]),Sz[id]=Sz[Lid]+Sz[Rid];
    return id;
}

void SegSplit(int id,int x,int &l,int &r,int L=1,int R=n){
    if(!id){l=r=0;return;}
    int M=(L+R)/2;
    if(Sz[id]==1){
        if(x)l=id,r=0;
        else r=id,l=0;
        return;
    }
    if(Sz[Lid]<=x){
        l=id,r=NewId();
        SegSplit(Rid,x-Sz[Lid],Rid,ch[r][1],M+1,R);
        f[r]=f[ch[r][1]],Sz[r]=Sz[ch[r][1]];
    }
    else{
        r=id,l=NewId();
        SegSplit(Lid,x,ch[l][0],Lid,L,M);
        f[l]=f[ch[l][0]],Sz[l]=Sz[ch[l][0]];
    }
    f[id]=pushup(f[Lid],f[Rid]),Sz[id]=Sz[Lid]+Sz[Rid];
    return;
}

struct node{
    int l,r,L,R,ky,sz,w,Rt;F g;
    node(int l=0,int r=0,int L=0,int R=0,int ky=0,int sz=0,int w=0,int Rt=0,F g=emp):
    l(l),r(r),L(L),R(R),ky(ky),sz(sz),w(w),Rt(Rt),g(g){}
}t[N];

void maintain(int id){
    t[id].sz=t[t[id].l].sz+t[t[id].r].sz+1;
    if(t[id].w)swap(f[t[id].Rt].s[0][1],f[t[id].Rt].s[1][0]);
    t[id].g=pushup(pushup(t[t[id].l].g,f[t[id].Rt]),t[t[id].r].g);
    if(t[id].w)swap(f[t[id].Rt].s[0][1],f[t[id].Rt].s[1][0]);
    return;
}

void splitL(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[id].R<x)l=id,splitL(t[id].r,x,t[id].r,r);
    else r=id,splitL(t[id].l,x,l,t[id].l);
    maintain(id);
    return;
}

void splitR(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[id].L<=x)l=id,splitR(t[id].r,x,t[id].r,r);
    else r=id,splitR(t[id].l,x,l,t[id].l);
    maintain(id);
    return;
}

void splitsz(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[t[id].l].sz<x)l=id,splitsz(t[id].r,x-t[t[id].l].sz-1,t[id].r,r);
    else r=id,splitsz(t[id].l,x,l,t[id].l);
    maintain(id);
    return;
}

int merge(int l,int r){
    if(!l||!r)return l|r;
    if(t[l].ky<=t[r].ky){
        t[l].r=merge(t[l].r,r),maintain(l);
        return l;
    }
    t[r].l=merge(l,t[r].l),maintain(r);
    return r;
}

void Split(int x,int y,int &L,int &M,int &R){
    splitL(rt,x,L,M),splitR(M,y,M,R);
    int s;
    splitsz(M,1,s,M);
    if(t[s].L<x){
        t[++tot]=node(0,0,t[s].L,x-1,rand(),1,t[s].w);
        if(!t[s].w)SegSplit(t[s].Rt,x-t[s].L,t[tot].Rt,t[s].Rt);
        else SegSplit(t[s].Rt,t[s].R-x+1,t[s].Rt,t[tot].Rt);
        maintain(s),maintain(tot);
        L=merge(L,tot),t[s].L=x;
    }
    M=merge(s,M);
    splitsz(M,t[M].sz-1,M,s);
    if(y<t[s].R){
        t[++tot]=node(0,0,y+1,t[s].R,rand(),1,t[s].w);
        if(!t[s].w)SegSplit(t[s].Rt,y-t[s].L+1,t[s].Rt,t[tot].Rt);
        else SegSplit(t[s].Rt,t[s].R-y,t[tot].Rt,t[s].Rt);
        maintain(s),maintain(tot);
        R=merge(tot,R),t[s].R=y;
    }
    M=merge(M,s);
    return;
}

void dfs(int id,int _id){
    if(!id)return;
    dfs(t[id].l,_id);
    t[_id].Rt=Merge(t[_id].Rt,t[id].Rt,1,n);
    maintain(_id);
    dfs(t[id].r,_id);
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
        ins(t[tot].Rt,1,n,a[i]);
        maintain(tot);
        rt=merge(rt,tot);
    }
    while(m--){
        int op=read(),l=read(),r=read(),L,M,R;
        Split(l,r,L,M,R);
        if(op<=2){
            t[++tot]=node(0,0,l,r,rand(),1,op-1);
            dfs(M,tot);
            rt=merge(merge(L,tot),R);
        }
        else{
            F x=t[M].g;
            _write(max(max(x.s[0][0],x.s[0][1]),max(x.s[1][0],x.s[1][1])));
            rt=merge(merge(L,M),R);
        }
    }
    return 0;
}
