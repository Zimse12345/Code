#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e3,Mod=998244353;
int n,m,a[N],mx[N],mn[N],c[N],fp[N][N];

inline int fpow(long long x,int y=Mod-2){
int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

signed main(){
    for(int i=0;i<N;i++){
        fp[i][0]=1;
        for(int j=1;j<N;j++)fp[i][j]=fp[i][j-1]*i%Mod;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    mn[0]=m+1;
    int ans=0;
    for(int i=1;i<=n;i++){
        mn[i]=mn[i-1];
        c[i]=c[i-1];
        if(a[i]!=-1)mn[i]=min(mn[i],a[i]);
        else c[i]++;
    }
    ans=fpow(m,c[n]);
    for(int i=n;i>=1;i--){
        mx[i]=max(mx[i+1],a[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=m;j>1;j--)if(mn[i]>=j&&mx[i+1]<=j-1){
            int A=fp[m-j+1][c[i]];
            int B=fp[j-1][c[n]-c[i]];
            int C=fp[m-j][c[i]];
            (ans+=A*B)%=Mod;
            if(mn[i]>j)(ans-=C*B)%=Mod;
        }
    }
    (ans+=Mod)%=Mod;
    printf("%lld\n",ans);
    return 0;
}


