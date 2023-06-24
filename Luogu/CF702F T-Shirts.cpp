// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int n,m,L[N],R[N],ans[N];
struct Tshirt{
    int c,q;
    Tshirt(int c=0,int q=0):c(c),q(q){}
    bool operator < (const Tshirt &_)const{
        if(q==_.q)return c<_.c;
        return q>_.q;
    }
}ts[N];

struct node{
    int l,r,v,ky;
    node(int l=0,int r=0,int v=0,int ky=0):
        l(l),r(r),v(v),ky(ky){};
}t[N];
set<int> s[32];
int sub[32],ad[32],rt[32],a[N],tot;

inline void split(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[id].v<=x)l=id,split(t[l].r,x,t[l].r,r);
    else r=id,split(t[r].l,x,l,t[r].l);
    return;
}

inline int merge(int l,int r){
    if(!l||!r)return l|r;
    if(t[l].ky<t[r].ky){
        t[l].r=merge(t[l].r,r);
        return l;
    }
    t[r].l=merge(l,t[r].l);
    return r;
}

inline void ins(int &Rt,int x){
    int l,r;
    split(Rt,t[x].v,l,r);
    Rt=merge(merge(l,x),r);
    return;
}

inline void Dfs(int id){
    if(!id)return;
    a[++tot]=id;
    Dfs(t[id].l),Dfs(t[id].r);
    return;
}

signed main(){
    n=read();
    for(int i=1,c,q;i<=n;i++){
        c=read(),q=read();
        ts[i]=Tshirt(c,q);
    }
    sort(ts+1,ts+n+1);
    for(int i=1;i<=30;i++)L[i]=R[i-1]+1,R[i]=(1<<i)-1;
    m=read();
    for(int i=1,b;i<=m;i++){
        b=read();
        t[i]=node(0,0,b,rand());
        for(int j=0;j<=30;j++)if(L[j]<=b&&b<=R[j])ins(rt[j],i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0,_t;j<=30;j++){
            if(R[j]<ts[i].c)continue;
            if(L[j]>=ts[i].c){
                sub[j]+=ts[i].c,++ad[j];
                split(rt[j],L[j]+sub[j]-1,_t,rt[j]);
                tot=0,Dfs(_t);
                for(int I=1,x;I<=tot;I++){
                    x=a[I];
                    t[x].v-=sub[j],ans[x]+=ad[j],t[x].l=t[x].r=0;
                    for(int k=0;k<=30;k++)if(L[k]<=t[x].v&&t[x].v<=R[k]){
                        t[x].v+=sub[k],ans[x]-=ad[k];
                        ins(rt[k],x);
                        break;
                    }
                }
                continue;
            }
            split(rt[j],ts[i].c+sub[j]-1,rt[j],_t);
            tot=0,Dfs(_t);
            for(int I=1,x;I<=tot;I++){
                x=a[I];
                t[x].v-=sub[j]+ts[i].c,ans[x]+=ad[j]+1,t[x].l=t[x].r=0;
                for(int k=0;k<=30;k++)if(L[k]<=t[x].v&&t[x].v<=R[k]){
                    t[x].v+=sub[k],ans[x]-=ad[k];
                    ins(rt[k],x);
                    break;
                }
            }
        }
    }
    for(int i=0;i<=30;i++){
        tot=0,Dfs(rt[i]);
        for(int j=1;j<=tot;j++)ans[a[j]]+=ad[i];
    }
    for(int i=1;i<=m;i++)wri(ans[i]);
    pc(10);
    return 0;
}

