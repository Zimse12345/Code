#include <bits/stdc++.h>
using namespace std;

const int N=5.01e5;
int k,n,m;
char s[N],t[N];
int f[N][50];

signed main(){
    cin>>k;
    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    int K=k+2;
    for(int j=-K;j<=K;j++){
        if(j>=0)f[0][j+K]=j;
        else f[0][j+K]=k+1;
    }
    for(int i=1;i<=n;i++){
        for(int j=-K;j<=K;j++){
            f[i][j+K]=k+1;
            if(0<=i+j&&i+j<=m){
                if(0<i+j)f[i][j+K]=f[i-1][j+K]+(s[i]==t[i+j]?0:1);
                if(j+1<=K)f[i][j+K]=min(f[i][j+K],f[i-1][j+K+1]+1);
                if(0<i+j&&j-1>=-K)f[i][j+K]=min(f[i][j+K],f[i][j+K-1]+1);
            }
        }
    }
    int x=m-n;
    if(-K<=x&&x<=K&&f[n][x+K]<=k)printf("Yes\n");
    else printf("No\n");
    return 0;
}


