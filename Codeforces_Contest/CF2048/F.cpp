#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e5,inf=1.01e18;
int T,n,a[N],b[N],t[N*4],f[N][64];

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

void build(int id,int L,int R){
    if(L==R)t[id]=L;
    else{
        build(Lid,L,M);
        build(Rid,M+1,R);
        if(b[t[Lid]]<=b[t[Rid]])t[id]=t[Lid];
        else t[id]=t[Rid];
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return t[id];
    if(r<=M)return query(Lid,L,M,l,r);
    if(l>M)return query(Rid,M+1,R,l,r);
    int lq=query(Lid,L,M,l,r),rq=query(Rid,M+1,R,l,r);
    if(b[lq]<=b[rq])return lq;
    return rq;
}

int mul(int x,int y){
    if(inf/y<x)return inf;
    return min(x*y,inf);
}

void sol(int L,int R,int p){
    if(R<L)return;
    int lp=(L<p?query(1,1,n,L,p-1):0);
    int rp=(p<R?query(1,1,n,p+1,R):0);
    sol(L,p-1,lp),sol(p+1,R,rp);
    for(int x=0;x<64;x++)if(x==0||f[lp][x]!=f[lp][x-1]){
        for(int y=0;x+y<64;y++)if(y==0||f[rp][y]!=f[rp][y-1]){
            int val=max(max(f[lp][x],f[rp][y]),a[p]),m=1;
            for(int z=0;x+y+z<64;z++){
                f[p][x+y+z]=min(f[p][x+y+z],(val+m-1)/m);
                if(m==inf)break;
                m=mul(m,b[p]);
            }
        }
    }
    for(int j=1;j<64;j++)f[p][j]=min(f[p][j],f[p][j-1]);
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            cin>>b[i];
            for(int j=0;j<64;j++)f[i][j]=inf;
        }
        build(1,1,n);
        int ans=0,p=query(1,1,n,1,n);
        sol(1,n,p);
        while(f[p][ans]>1)++ans;
        printf("%lld\n",ans);
    }
    return 0;
}


