// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=2.01e6;
int n,m,val[N],sum[N],tim[N],ad[N],sd[N],utim[N];

inline void maintain(int id,int _id){
    sd[id]+=sd[_id]+ad[id]*(utim[_id]-utim[id]);
    ad[id]+=ad[_id],utim[id]=utim[_id];
    return;
}

inline void pushdown(int id){
    maintain(Lid,id),maintain(Rid,id);
    ad[id]=sd[id]=0;
    return;
}

void update(int id,int L,int R,int x,int y,int T){
    if(L==R){
        sum[x]+=(utim[id]-tim[x])*val[x]+sd[id]*x;
        val[x]+=ad[id]*x,sum[x]+=val[x]*(T-utim[id]);
        ad[id]=sd[id]=0,utim[id]=tim[x]=T;
        sum[x]+=y-val[x],val[x]=y;
        return;
    }
    pushdown(id);
    if(x<=M)update(Lid,L,M,x,y,T);
    else update(Rid,M+1,R,x,y,T);
    return;
}

int query(int id,int L,int R,int x,int T){
    if(L==R){
        sum[x]+=(utim[id]-tim[x])*val[x]+sd[id]*x;
        val[x]+=ad[id]*x,sum[x]+=val[x]*(T-utim[id]);
        ad[id]=sd[id]=0,utim[id]=tim[x]=T;
        return val[x];
    }
    pushdown(id);
    if(x<=M)return query(Lid,L,M,x,T);
    return query(Rid,M+1,R,x,T);
}

int qsum(int id,int L,int R,int x,int T){
    if(L==R){
        sum[x]+=(utim[id]-tim[x])*val[x]+sd[id]*x;
        val[x]+=ad[id]*x,sum[x]+=val[x]*(T-utim[id]);
        ad[id]=sd[id]=0,utim[id]=tim[x]=T;
        return sum[x];
    }
    pushdown(id);
    if(x<=M)return qsum(Lid,L,M,x,T);
    return qsum(Rid,M+1,R,x,T);
}

signed main(){
    // ifile("a.in");
    // ofile("a.out");

    n=read(),m=read();
    for(int i=1,a,b;i<=m;i++){
        a=read(),b=read();
        int x=query(1,1,n,a,i),y=query(1,1,n,b,i);
        swap(x,y),x+=b,y+=a;
        sd[1]+=ad[1]*(i-utim[1])+1,ad[1]+=1,utim[1]=i;
        update(1,1,n,a,x,i),update(1,1,n,b,y,i);
    }
    for(int i=1;i<=n;i++)write_(qsum(1,1,n,i,m));
    pc(10);
    return 0;
}

