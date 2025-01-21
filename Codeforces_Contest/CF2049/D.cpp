#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=210,inf=1e18;
int T,n,m,a[N][N],f[N][N],g[N],k;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        f[0][1]=0;
        for(int i=2;i<=m;i++)f[0][i]=inf;
        for(int i=1;i<=n;i++){
            g[0]=inf;
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                g[j]=min(f[i-1][j],g[j-1])+a[i][j];
                f[i][j]=g[j];
            }
            for(int c=1;c<m;c++){
                int t=a[i][1];
                for(int j=1;j<m;j++)a[i][j]=a[i][j+1];
                a[i][m]=t;
                for(int j=1;j<=m;j++){
                    g[j]=min(f[i-1][j],g[j-1])+a[i][j];
                    f[i][j]=min(f[i][j],g[j]+c*k);
                }
            }
        }
        printf("%lld\n",f[n][m]);
    }
    return 0;
}


