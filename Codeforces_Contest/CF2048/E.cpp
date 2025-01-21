#include <bits/stdc++.h>
using namespace std;

const int N=2.01e3;
int T,n,m,a[N][N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        if(m>n*2-1){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int t=1,c=1;t<n*2;t+=2,c++){
            int l=1,r=t;
            for(int i=1;i<=n*4;i++){
                a[l][r]=c;
                if(i&1){
                    ++l;
                    if(l>n*2)l=1;
                }
                else{
                    ++r;
                    if(r>n*2)r=1;
                }
            }
        }
        for(int i=1;i<=n*2;i++){
            for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}


