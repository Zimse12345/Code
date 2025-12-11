#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e9;
int T,n,x[N],y[N],lx,rx,ly,ry; 

int query(char c,int k){
    printf("? %c %lld\n",c,k);
    fflush(stdout);
    int res=0;
    cin>>res;
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        lx=inf,rx=-inf;
        ly=inf,ry=-inf;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
            lx=min(lx,x[i]);
            rx=max(rx,x[i]);
            ly=min(ly,y[i]);
            ry=max(ry,y[i]);
        }
        int mn1=inf*2,mn2=inf*2;
        for(int i=1;i<=n;i++){
            mn1=min(mn1,x[i]-lx+y[i]-ly);
            mn2=min(mn2,rx-x[i]+y[i]-ly);
        }
        query('L',inf);
        query('L',inf);
        query('D',inf);
        int v1=query('D',inf)-mn1;
        query('R',inf);
        query('R',inf);
        query('R',inf);
        int v2=query('R',inf)-mn2;
        int Y=(lx+inf*4+ly*2-rx-v1-v2)/2;
        int X=lx+ly-Y-v1;
        X+=inf*2,Y+=inf*2;
        printf("! %lld %lld\n",X,Y);
        fflush(stdout);
    }
    return 0;
}


