#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,q,f[32][32][1024]; 

signed main(){
    cin>>n>>q;
    f[0][0][0]=1;
    for(int x=0;x<=n;x++){
        for(int y=0;y<=n;y++){
            f[x][y][0]=1;
            for(int i=2;i<=x;i++){
                for(int j=2;j<=y;j++){
                    for(int t=0;t<=(x-i)*(y-j);t++)if(f[x-i][y-j][t]){
                        f[x][y][t+i*j]=1;
                        f[x][y][t]=1;
                    }
                }
            }
        }
    }
    while(q--){
        int k=0;
        cin>>k;
        if(f[n][n][n*n-k])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


