#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5.01e3,Mod=998244353;
int n,a[N],p[N],f[N][N];

inline int fpow(long long x,int y=Mod-2){
int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

signed main(){
    cin>>n;
    a[0]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<=n;x++){
            //f[i-1][x]
            for(int v=x+1;v<=n;v++){
                if(a[i-1]!=-1&&a[i-1]!=x)continue;
                (f[i][v]+=f[i-1][x])%=Mod;
            }
            if(a[i-1]!=-1&&a[i-1]<x){
                (f[i][x]+=f[i-1][x])%=Mod;
            }
            int rm=x-i;
            for(int p=i+1;p<=n;p++)if(a[p]!=-1&&a[p]<x)--rm;
            if(a[i-1]==-1&&rm>0){
                (f[i][x]+=f[i-1][x]*rm)%=Mod;
            }
        }
    }
//    (f[n][n]*=fpow(n-1))%=Mod;
    printf("%lld\n",f[n][n]);
    return 0;
}


