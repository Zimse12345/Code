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
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

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

int n,m,q,sum[N],len[N],tag[N],sumx[N],sumy[N];
int ans,ck;

struct line{
    int l,r;
    line(int l=0,int r=0):l(l),r(r){}
};
vector<line> px[N],py[N];

void pushdown(int id){
    if(tag[id]){
        if(Rid<N)tag[Lid]^=1,tag[Rid]^=1;
        sum[id]=len[id]-sum[id],tag[id]=0;
    }
    return;
}

void build(int id,int L,int R){
    len[id]=R-L+1,sum[id]=tag[id]=0;
    if(L^R)build(Lid,L,M),build(Rid,M+1,R);
    return;
}

void update(int id,int L,int R,int l,int r){
    pushdown(id);
    if(l<=L&&r>=R)tag[id]=1,pushdown(id);
    else if(r<L||R<l)return;
    else{
        update(Lid,L,M,l,r),update(Rid,M+1,R,l,r);
        sum[id]=sum[Lid]+sum[Rid];
    }
    return;
}

signed main(){
    n=read(),m=read(),q=read();
    for(int i=1,xl,yl,xr,yr;i<=q;i++){
        xl=read(),yl=read(),xr=read(),yr=read();
        px[xl].pb(line(yl,yr)),px[xr+1].pb(line(yl,yr));
        py[yl].pb(line(xl,xr)),py[yr+1].pb(line(xl,xr));
    }
    build(1,1,m);
    for(int i=1;i<=n;i++){
        for(unsigned j=0;j<px[i].size();j++)update(1,1,m,px[i][j].l,px[i][j].r);
        sumx[i]=sum[1]&1,ck|=sum[1]&1,ans+=sum[1];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        for(unsigned j=0;j<py[i].size();j++)update(1,1,n,py[i][j].l,py[i][j].r);
        sumy[i]=sum[1]&1,ck|=sum[1]&1;
    }
    if(!ck){
        _write(ans);
        return 0;
    }
    int cntx[2]={0,0},cnty[2]={0,0};
    for(int i=1;i<=n;i++)cntx[sumx[i]]++;
    for(int i=1;i<=m;i++)cnty[sumy[i]]++;
    if(n%2==0&&m%2==0){
        _write(ans+cntx[0]*cnty[1]+cntx[1]*cnty[0]);
        return 0;
    }
    if(n%2&&m%2){
        _write(-1);
        return 0;
    }
    if(n%2==0){
        for(int i=1;i<=n;i++)if(sumx[i]){
            _write(-1);
            return 0;
        }
        int tot=0;
        for(int i=1;i<=m;i++)tot+=sumy[i];
        if(tot&1)_write(-1);
        else _write(ans+tot*n);
    }
    else{
        for(int i=1;i<=m;i++)if(sumy[i]){
            _write(-1);
            return 0;
        }
        int tot=0;
        for(int i=1;i<=n;i++)tot+=sumx[i];
        if(tot&1)_write(-1);
        else _write(ans+tot*m);
    }
    return 0;
}
