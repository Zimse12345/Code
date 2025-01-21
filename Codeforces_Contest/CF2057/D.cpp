#include <bits/stdc++.h>
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)
using namespace std;

const int N=2.01e5;
int T,n,q,a[N];

struct node{
    int ln,lx,rn,rx,s;
    node(int ln=0,int lx=0,int rn=0,int rx=0,int s=0):ln(ln),lx(lx),rn(rn),rx(rx),s(s){}
}t[N*8];

node merge(node x,node y){
    return node(max(x.ln,y.ln),max(x.lx,y.lx),max(x.rn,y.rn),max(x.rx,y.rx)
    ,max(max(x.s,y.s),max(x.ln+y.rx,x.lx+y.rn)));
}

void build(int id,int L,int R){
    if(L==R){
        t[id]=node(-a[L]+L,a[L]+L,-a[R]-R,a[R]-R,0);
    }
    else{
        build(Lid,L,M);
        build(Rid,M+1,R);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

void update(int id,int L,int R,int x){
    if(L==R){
        t[id]=node(-a[L]+L,a[L]+L,-a[R]-R,a[R]-R,0);
    }
    else{
        if(x<=M)update(Lid,L,M,x);
        else update(Rid,M+1,R,x);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        build(1,1,n);
        printf("%d\n",t[1].s);
        while(q--){
            int p,x;
            cin>>p>>x;
            a[p]=x;
            update(1,1,n,p);
            printf("%d\n",t[1].s);
        }
    }
    return 0;
}


