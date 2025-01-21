#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e3;
int T,n,m,a[N][N];
char s[N];

int sx(int x){
    int sum=0;
    for(int i=1;i<=m;i++)sum+=a[x][i];
    return sum;
}

int sy(int y){
    int sum=0;
    for(int i=1;i<=n;i++)sum+=a[i][y];
    return sum;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int x=1,y=1;
        for(int i=1;i<=n+m-2;i++){
            if(s[i]=='D'){
                a[x][y]=-sx(x);
                ++x;
            }
            if(s[i]=='R'){
                a[x][y]=-sy(y);
                ++y;
            }
        }
        a[n][m]=-sx(n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)printf("%lld ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}


