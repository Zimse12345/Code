// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
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

const int N=1.01e6;
int n,m,mx[N],ad[N],ans;

struct line{
    int l,r;
    line(int l=0,int r=0):l(l),r(r){}
    bool operator < (const line &_)const{return l<_.l;}
}p[N];

inline void pushdown(int id){
    if(ad[id]!=0){
        if(Rid<N)ad[Lid]+=ad[id],ad[Rid]+=ad[id];
        mx[id]+=ad[id],ad[id]=0;
    }
    return;
}

void update(int id,int L,int R,int l,int r,int x){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)ad[id]+=x,pushdown(id);
    else{
        update(Lid,L,M,l,r,x),update(Rid,M+1,R,l,r,x);
        mx[id]=max(mx[Lid],mx[Rid]);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    pushdown(id);
    if(r<L||R<l)return -INF;
    if(l<=L&&r>=R)return mx[id];
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    n=read(),m=read()+1;
    for(int i=1,l,r;i<=n;i++){
        l=read(),r=read();
        p[i]=line(l,r);
    }
    sort(p+1,p+n+1);
    for(int i=1;i<m;i++)update(1,0,m,0,i,-1);
    for(int i=1;i<=n;i++){
        update(1,0,m,0,p[i].r,1);
        _max(ans,query(1,0,m,p[i].l+1,m)-min(m-1,p[i].l));
    }
    _max(ans,n-(m-1));
    _write(ans);
    return 0;
}

