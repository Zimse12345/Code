#include <bits/stdc++.h>
#define int long long
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)
using namespace std;

const int N=4.01e5,inf=1e18;
int n,a[N],b[N],q;

struct node{
    int l,r,sl,sr,s,ss,lr,sum;
    node(int l=0,int r=0,int sl=0,int sr=0,int s=0,int ss=0,int lr=0,int sum=0):
        l(l),r(r),sl(sl),sr(sr),s(s),ss(ss),lr(lr),sum(sum){}
}t[N*8],f;

node merge(node x,node y){
    node m=f;
    m.l=max(x.l,y.l+x.sum);
    m.r=max(x.r+y.sum,y.r);
    m.s=max(x.s,y.s);
    m.s=max(m.s,x.r+y.l);
    m.sl=max(x.sl,y.sl+x.sum);
    m.sl=max(m.sl,x.l+y.s);
    m.sr=max(x.sr+y.sum,y.sr);
    m.sr=max(m.sr,x.s+y.r);
    m.ss=max(x.ss,y.ss);
    m.ss=max(m.ss,max(x.sr+y.l,x.r+y.sl));
    m.ss=max(m.ss,x.s+y.s);
    m.lr=max(max(x.lr+y.sum,x.sum+y.lr),m.lr);
    m.lr=max(m.lr,x.l+y.r);
    m.sr=max(m.sr,x.r+y.lr);
    m.sl=max(m.sl,x.lr+y.l);
    m.sum=x.sum+y.sum;
    return m;
}

void build(int id,int L,int R){
    if(L==R){
        t[id]=f;
        t[id].sum=a[id];
        t[id].l=t[id].r=a[L]+b[L];
        t[id].s=a[L]+b[L]*2;
    }
    else{
        build(Lid,L,M);
        build(Rid,M+1,R);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

void update(int id,int L,int R,int ty,int x,int y){
    if(L==R){
        if(ty==1)a[x]=y;
        else b[x]=y;
        t[id]=f;
        t[id].sum=a[L];
        t[id].l=t[id].r=a[L]+b[L];
        t[id].s=a[L]+b[L]*2;
    }
    else{
        if(x<=M)update(Lid,L,M,ty,x,y);
        else update(Rid,M+1,R,ty,x,y);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

node query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return t[id];
    if(r<=M)return query(Lid,L,M,l,r);
    if(l>M)return query(Rid,M+1,R,l,r);
    return merge(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    f.l=f.r=f.sl=f.sr=f.s=f.ss=f.lr=-inf;
    f.sum=0;
    build(1,1,n);
    cin>>q;
    while(q--){
        int ty,x,y;
        cin>>ty>>x>>y;
        if(ty<=2)update(1,1,n,ty,x,y);
        else printf("%lld\n",query(1,1,n,x,y).ss);
    }
    return 0;
}


