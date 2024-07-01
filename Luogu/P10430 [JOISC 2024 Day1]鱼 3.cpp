// Author:Zimse  Data:2024-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)
namespace OI{const int INF=1.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.21e6;
int n,D,c[N],q,ans[N];
int stk[N],top,sum[N],ad[N],mn[N];

struct node{
    int l,id;
    node(int l=0,int id=0):l(l),id(id){}
};
vector<node> Q[N];

void pushdown(int id,int len){
    sum[id]+=ad[id]*len;
    mn[id]-=ad[id]*D;
    if(Rid<N)ad[Lid]+=ad[id],ad[Rid]+=ad[id];
    ad[id]=0;
    return;
}

void build(int id,int L,int R){
    if(L==R)mn[id]=c[L];
    else{
        build(Lid,L,M);
        build(Rid,M+1,R);
        mn[id]=min(mn[Lid],mn[Rid]);
    }
    return;
}

void update(int id,int L,int R,int l,int r,int x){
    pushdown(id,R-L+1);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)ad[id]+=x,pushdown(id,R-L+1);
    else{
        update(Lid,L,M,l,r,x);
        update(Rid,M+1,R,l,r,x);
        sum[id]=sum[Lid]+sum[Rid];
        mn[id]=min(mn[Lid],mn[Rid]);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    pushdown(id,R-L+1);
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R)return sum[id];
    return query(Lid,L,M,l,r)+query(Rid,M+1,R,l,r);
}

int qmin(int id,int L,int R,int l,int r){
    pushdown(id,R-L+1);
    if(r<L||R<l)return INF;
    if(l<=L&&r>=R)return mn[id];
    return min(qmin(Lid,L,M,l,r),qmin(Rid,M+1,R,l,r));
}

signed main(){
    n=read(),D=read();
    for(int i=1;i<=n;i++)c[i]=read();
    build(1,1,n);
    c[0]=-INF;
    q=read();
    for(int i=1,l,r;i<=q;i++){
        l=read(),r=read();
        Q[r].push_back(node(l,i));
    }
    for(int i=1;i<=n;i++){
        stk[++top]=i;
        while(1){
            int Lh=c[stk[top]-1]-query(1,1,n,stk[top]-1,stk[top]-1)*D;
            int Rh=c[stk[top]]-query(1,1,n,stk[top],stk[top])*D;
            if(Lh<=Rh)break;
            int t=(Lh-Rh-1)/D+1;
            update(1,1,n,stk[top-1],stk[top]-1,t);
            --top;
        }
        for(unsigned j=0;j<Q[i].size();j++){
            if(qmin(1,1,n,Q[i][j].l,i)<0)ans[Q[i][j].id]=-1;
            else ans[Q[i][j].id]=query(1,1,n,Q[i][j].l,i);
        }
    }
    for(int i=1;i<=q;i++)_wri(ans[i]);
    return 0;
}

