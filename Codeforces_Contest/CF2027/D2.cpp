#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18,Mod=1000000007;
int T,n,m,a[N],b[N],s[N];
vector<int> pre[N],f[N],g[N],sumg[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i],s[i]=s[i-1]+a[i];
            pre[i].resize(m+1);
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
            for(int j=1,p=1;j<=n;j++){
                while(p<j&&s[j]-s[p-1]>b[i])++p;
                pre[j][i]=((s[j]-s[p-1]<=b[i])?p:-1);
            }
        }
        f[0].resize(m+1);
        g[0].resize(m+1);
        sumg[0].resize(m+1);
        for(int i=0;i<=m;i++)g[0][i]=sumg[0][i]=1;
        for(int i=1;i<=n;i++){
            f[i].resize(m+1);
            g[i].resize(m+1);
            sumg[i].resize(m+1);
            f[i][0]=inf,g[i][0]=sumg[i][0]=0;
            for(int j=1;j<=m;j++){
                f[i][j]=f[i][j-1];
                g[i][j]=g[i][j-1];
                if(pre[i][j]>0){
                    int pos=pre[i][j]-1;
                    int x=f[pos][j]+(m-j);
                    int L=pos,R=i-1,k=pos;
                    while(L<=R){
                        int M=(L+R)/2;
                        if(f[pos][j]==f[M][j])k=M,L=M+1;
                        else R=M-1;
                    }
                    int gg=sumg[k][j];
                    if(pos>0)gg=(gg-sumg[pos-1][j]+Mod)%Mod;
                    if(x<f[i][j])f[i][j]=x,g[i][j]=gg;
                    else if(x==f[i][j])(g[i][j]+=gg)%=Mod;
                }
                sumg[i][j]=(g[i][j]+sumg[i-1][j])%Mod;
            }
        }
        if(f[n][m]==inf)printf("-1\n");
        else printf("%lld %lld\n",f[n][m],(g[n][m]+Mod)%Mod);
    }
    return 0;
}


