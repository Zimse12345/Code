#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],p[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        int ans=1;
        for(int j=1;j<=n;j++){
            for(int i=1;i<=m;i++){
                cin>>a[i];
                if(a[i]%n!=a[1]%n)ans=0;
            }
            p[a[1]%n+1]=j;
        }
        if(ans){
            for(int i=1;i<=n;i++)printf("%d ",p[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}


