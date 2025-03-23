#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,INF=1e18;
int M,nn,mm,n,f[N][4];

struct node{
    int p,ty;
    node(int p=0,int ty=0):p(p),ty(ty){}
    bool operator < (const node& _)const{return p<_.p;}
}a[N];

signed main(){
    cin>>M>>nn>>mm;
    for(int i=1,l,r;i<=nn;i++){
        cin>>l>>r;
        for(int j=l;j<=r;j+=M)a[++n]=node(j,0);
    }
    for(int i=1,l,r;i<=mm;i++){
        cin>>l>>r;
        for(int j=l;j<=r;j+=M)a[++n]=node(j,1);
    }
    sort(a+1,a+n+1);
    if(a[1].ty==1)f[1][0]=f[1][1]=INF;
    
    for(int i=2;i<=n;i++){
        int d=a[i].p-a[i-1].p;
        f[i][0]=f[i-1][0]+d;
        f[i][1]=f[i-1][1]+d*2;
        int v=min(f[i-1][0],f[i-1][1]);
        f[i][2]=min(v,f[i-1][2]+d);
        f[i][3]=min(v,f[i-1][3]+d*2);
        if(a[i].ty==0){
            f[i][0]=min(v,f[i][3]);
            f[i][1]=min(v,f[i][2]);
            f[i][2]=f[i][3]=INF;
        }
    }
    printf("%lld\n",min(f[n][0],f[n][1]));
    return 0;
}
