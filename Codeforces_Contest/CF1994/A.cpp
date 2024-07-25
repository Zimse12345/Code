#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int T,n,m,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>a[(i-1)*m+j];
        }
        if(n*m==1)printf("-1\n");
        else{
            a[0]=a[n*m];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)printf("%d ",a[(i-1)*m+j-1]);
                printf("\n");
            }
        }
    }
    return 0;
}



