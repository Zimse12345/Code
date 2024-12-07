#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],f[N],b[N],pm[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)b[i]=f[i]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pm[i]=max(pm[i-1],a[i]);
            b[a[i]]=i;
        }
        for(int i=2;i<=n;i++)b[i]=max(b[i],b[i-1]);
        for(int i=1;i<=n;i++){
            if(f[i-1]>=i)f[i]=f[i-1];
            else{
                int p=i;
                while(b[pm[p]-1]>p)p=b[pm[p]-1];
                f[i]=p;
            }
            printf("%d ",pm[f[i]]);
        }
        printf("\n");
    }
    return 0;
}


