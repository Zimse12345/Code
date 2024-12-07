#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int T,n,m,f[N][N];
char a[N],b[N],c[N+N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",a+1);
        scanf("%s",b+1);
        scanf("%s",c+1);
        n=strlen(a+1);
        m=strlen(b+1);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                f[i][j]=i+j;
                if(i)f[i][j]=min(f[i][j],f[i-1][j]+(a[i]==c[i+j]?0:1));
                if(j)f[i][j]=min(f[i][j],f[i][j-1]+(b[j]==c[i+j]?0:1));
            }
        }
        printf("%d\n",f[n][m]);
    }
    return 0;
}


