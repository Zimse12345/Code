#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=1e9;
int T,n,k,f[N],g[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=k;i++)f[i]=inf;
        while(n--){
            int a,b;
            cin>>a>>b;
            for(int i=0;i<=max(a*b,k);i++)g[i]=inf;
            for(int i=0;i<=a;i++){
                for(int j=0;j<=b;j++){
                    g[i+j]=min(g[i+j],i*b+j*a-i*j);
                }
            }
            for(int j=k;j>=1;j--){
                for(int i=1;i<=j;i++)f[j]=min(f[j],f[j-i]+g[i]);
            }
        }
        if(f[k]==inf)f[k]=-1;
        printf("%d\n",f[k]);
    }
    return 0;
}


