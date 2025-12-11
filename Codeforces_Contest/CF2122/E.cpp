#include <bits/stdc++.h>
using namespace std;

const int N=1024,Mod=998244353;
int T,n,k,a[2][N],f[N],g[N],h[N],F[N];
int ff,FF; 
vector<int> p[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[0][i];
        for(int i=1;i<=n;i++)cin>>a[1][i];
        for(int i=0;i<=k;i++)f[i]=F[i]=0;
        ff=1;
        for(int i=1;i<n;i++){
            for(int x=1;x<=k;x++)if(a[0][i+1]==x||a[0][i+1]==-1){
                for(int y=1;y<=k;y++)if(a[1][i]==y||a[1][i]==-1){
                    if(x<y)++g[y-x];
                    else ++h[x-y];
                }
            }
            for(int y=0;y<=k;y++){
                for(int x=0;x<=k;x++){
                    (F[y]+=1ll*f[x]*g[y]%Mod)%=Mod;
                    if(x>=y)(F[x-y]+=1ll*f[x]*h[y]%Mod)%=Mod;
                }
                (FF+=1ll*ff*h[y]%Mod)%=Mod;
                (F[y]+=1ll*ff*g[y]%Mod)%=Mod;
            }
            for(int x=0;x<=k;x++)f[x]=F[x],g[x]=h[x]=F[x]=0;
            ff=FF,FF=0;
        }
        int ans=ff;
        for(int i=0;i<=k;i++)(ans+=f[i])%=Mod;
        if(a[0][1]==-1)ans=1ll*ans*k%Mod;
        if(a[1][n]==-1)ans=1ll*ans*k%Mod;
        printf("%d\n",ans);
    }
    return 0;
}


