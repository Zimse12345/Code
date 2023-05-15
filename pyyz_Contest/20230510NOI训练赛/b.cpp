// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid (Lid|1)

namespace Zimse{const int INF=1.01e15,Mod=998244353;
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

const int N=4.01e5;
int T,n,k,a[N],b[N],B[N];
int Set[N],Add[N],val[N],mx[N],rv[N],mxpos[N];
bool Tag[N];

inline void pushdown(int id,bool isLeaf){
    if(isLeaf){
        if(Tag[id])val[id]=Set[id],Tag[id]=false;
        if(Add[id])val[id]+=Add[id],Add[id]=0;
        mx[id]=rv[id]=val[id];
        return;
    }
    if(Tag[id]){
        Tag[Lid]=Tag[Rid]=true,Tag[id]=false;
        Set[Lid]=Set[Rid]=mx[id]=rv[id]=Set[id],Add[Lid]=Add[Rid]=0;
    }
    if(Add[id])Add[Lid]+=Add[id],Add[Rid]+=Add[id],mx[id]+=Add[id],rv[id]+=Add[id],Add[id]=0;
    return;
}

inline void update1(int id,int L,int R,int l,int r,int x){
    pushdown(id,L==R);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)Add[id]+=x,pushdown(id,L==R);
    else update1(Lid,L,M,l,r,x),update1(Rid,M+1,R,l,r,x),mx[id]=max(mx[Lid],mx[Rid]),rv[id]=rv[Rid];
    return;
}

inline void update2(int id,int L,int R,int l,int r,int x){
    pushdown(id,L==R);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)Tag[id]=true,Set[id]=x,pushdown(id,L==R);
    else update2(Lid,L,M,l,r,x),update2(Rid,M+1,R,l,r,x),mx[id]=max(mx[Lid],mx[Rid]),rv[id]=rv[Rid];
    return;
}

inline int query(int id,int L,int R,int x){
    pushdown(id,L==R);
    if(L==R)return val[id];
    if(x<=M)return query(Lid,L,M,x);
    return query(Rid,M+1,R,x);
}

inline int findpos(int id,int L,int R,int x){
    pushdown(id,L==R);
    if(mx[id]<x)return 0;
    if(L==R)return L;
    int r=findpos(Rid,M+1,R,x);
    return r?r:findpos(Lid,L,M,x);
}

inline void build(int id,int L,int R){
    mxpos[id]=L;
    if(L!=R)build(Lid,L,M),build(Rid,M+1,R);
    return;
}

inline void update(int id,int L,int R,int x){
    if(L!=R){
        if(x<=M)update(Lid,L,M,x);
        else update(Rid,M+1,R,x);
        mxpos[id]=mxpos[Lid];
        if(B[mxpos[Lid]]<B[mxpos[Rid]])mxpos[id]=mxpos[Rid];
    }
    return;
}

inline int qrymax(int id,int L,int R,int l){
    if(l<=L)return mxpos[id];
    if(l>M)return qrymax(Rid,M+1,R,l);
    int lp=qrymax(Lid,L,M,l),rp=mxpos[Rid];
    return B[lp]<B[rp]?rp:lp;
}

int V,Rlim;
inline int Findpos(int id,int L,int R,int Mx){
    pushdown(id,L==R);
    if(L>Rlim)return 0;
    if(R<=Rlim&&V-max(Mx,B[R])<=rv[id])return 0;
    if(L==R)return L;
    int l=Findpos(Lid,L,M,max(Mx,B[mxpos[Rid]]));
    return l?l:Findpos(Rid,M+1,R,Mx);
}

int mmx;
inline bool check(int x){
    for(int i=0;i<=n*4+8;i++)Tag[i]=false,Add[i]=val[i]=mx[i]=0;
    for(int i=1;i<=n;i++)B[i]=-1;
    build(1,1,n);
    int rm=k,mn=0,pos=0,p=0,_p=0,v=0,rpos=0;
    for(int i=1;i<=n;i++){
        B[i]=b[i],update(1,1,n,i);
        if(a[i]>=0)update1(1,1,n,1,i,a[i]);
        else{
            pos=findpos(1,1,n,-a[i]);
            update1(1,1,n,1,pos,a[i]),update2(1,1,n,pos+1,i,0);
        }
        while(1){
            V=query(1,1,n,1);
            if(V<x)break;
            if(!rm)return true;
            --rm,Rlim=i;
            rpos=Findpos(1,1,n,0);
            if(!rpos)rpos=i;
            mn=INF,pos=0;
            _p=qrymax(1,1,n,rpos);
            for(int j=rpos;j>=max(1ll,rpos-1);j--){
                if(j<rpos&&B[_p]<B[j])_p=j;
                v=max(V-B[_p],j<n?query(1,1,n,j+1):0);
                if(v<mn)mn=v,pos=_p;
            }
            v=pos<n?query(1,1,n,pos+1):0,p=min(pos,findpos(1,1,n,v+B[pos]));
            update1(1,1,n,1,p,-B[pos]),update2(1,1,n,p+1,pos,v);
            B[pos]=0,update(1,1,n,pos);
        }
        _max(mmx,V);
    }
    return false;
}

void sub1(){
    sort(b+1,b+n+1);
    int sum=0;
    for(int i=1;i<=n;i++)sum+=a[i];
    for(int i=n;i>=n-k+1;i--)sum-=b[i];
    _write(sum);
    return;
}

int premx[N],presum[N],sufmx[N],sufsum[N];
void sub2(){
    for(int i=1;i<=n;i++){
        presum[i]=max(presum[i-1]+a[i],0ll);
        premx[i]=max(premx[i-1],presum[i]);
    }
    sufsum[n+1]=sufmx[n+1]=0;
    for(int i=n;i>=1;i--){
        sufsum[i]=max(sufsum[i+1]+a[i],0ll);
        sufmx[i]=max(sufmx[i+1],sufsum[i]);
    }
    int ans=INF;
    for(int i=1;i<=n;i++){
        _min(ans,max(max(premx[i-1],sufmx[i+1]),presum[i-1]+sufsum[i+1]+a[i]-b[i]));
    }
    _write(ans);
    return;
}

signed main(){
    // ifile("b.in");
    // ofile("b.out");

    T=read();
    while(T--){
        n=read(),k=read();
        int sum=0;
        int tag=1;
        for(int i=1;i<=n;i++)a[i]=read(),sum+=max(a[i],0ll);
        for(int i=1;i<=n;i++){
            b[i]=read();
            if(a[i]-b[i]<0)tag=0;
        }
        if(tag){
            sub1();
            continue;
        }
        if(k==1){
            sub2();
            continue;
        }
        int L=1,R=sum,ans=0;
        while(L<=R){
            mmx=0;
            if(check(M))ans=M,L=M+1;
            else R=mmx;
        }
        _write(ans);
    }
    return 0;
}

