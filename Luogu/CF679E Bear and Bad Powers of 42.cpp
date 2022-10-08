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

#define int long long
#define ull unsigned long long
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],pow42[64];
int mn[N],as[N],Lg[N],st[N],ad[N],tag;

void build(int L,int R,int id){
    if(L==R){
        while(a[L]>=pow42[Lg[id]])++Lg[id];
        mn[id]=pow42[Lg[id]]-a[L],as[id]=1;
    }
    else{
        build(L,M,Lid),build(M+1,R,Rid);
        mn[id]=min(mn[Lid],mn[Rid]);
    }
    return;
}

void pushdown(int id){
    if(st[id]){
        ad[Lid]=ad[Rid]=0,st[Lid]=st[Rid]=st[id];
        Lg[id]=0;
        while(st[id]>=pow42[Lg[id]])++Lg[id];
        mn[id]=pow42[Lg[id]]-st[id],as[id]=1,st[id]=0;
    }
    if(ad[id]){
        int x=ad[id];
        ad[Lid]+=x,ad[Rid]+=x,ad[id]=0;
        mn[id]-=x;
        if(mn[id]<=0){
            if(as[id]){
                int v=pow42[Lg[id]]-mn[id];
                while(v>pow42[Lg[id]])++Lg[id];
                while(v==pow42[Lg[id]])++Lg[id],tag=1;
                mn[id]=pow42[Lg[id]]-v;
            }
            else{
                pushdown(Lid),pushdown(Rid);
                mn[id]=min(mn[Lid],mn[Rid]);
            }
        }
    }
    return;
}

void update(int L,int R,int id,int l,int r,int x){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)st[id]=x,pushdown(id);
    else{
        update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
        mn[id]=min(mn[Lid],mn[Rid]);
        if(as[Lid]&&as[Rid]&&Lg[Lid]==Lg[Rid]&&mn[Lid]==mn[Rid])as[id]=1;
        else as[id]=0;
    }
    return;
}

void add(int L,int R,int id,int l,int r,int x){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)ad[id]+=x,pushdown(id);
    else{
        add(L,M,Lid,l,r,x),add(M+1,R,Rid,l,r,x);
        mn[id]=min(mn[Lid],mn[Rid]);
        if(as[Lid]&&as[Rid]&&Lg[Lid]==Lg[Rid]&&mn[Lid]==mn[Rid])as[id]=1,Lg[id]=Lg[Lid];
        else as[id]=0;
    }
    return;
}

int query(int L,int R,int id,int x){
    pushdown(id);
    if(L==R)return pow42[Lg[id]]-mn[id];
    return x<=M?query(L,M,Lid,x):query(M+1,R,Rid,x);
}

signed main(){
    pow42[0]=1;
    for(int i=1;i<64;i++)pow42[i]=pow42[i-1]*42ll;
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,n,1);
    while(m--){
        int op=read();
        if(op==1)printf("%lld\n",query(1,n,1,read()));
        else if(op==2){
            int l=read(),r=read(),x=read();
            update(1,n,1,l,r,x);
        }
        else{
            int l=read(),r=read(),x=read();
            while(1){
                tag=0;
                add(1,n,1,l,r,x);
                if(!tag)break;
            }
        }
    }
	return 0;
}
