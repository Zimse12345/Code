#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,m,to[1024][30],f[200][1024],ans[100];
char s[N];

signed main(){
    cin>>n>>m;
    scanf("%s",s);
    for(int i=0;i<(1<<n);i++){
        for(char c='a';c<='z';c++){
            int x=i;
            for(int j=n-1;j>=0;j--){
                if(s[j]==c&&(x&(1<<j))==0){
                    x^=(1<<j);
                    for(int k=j+1;k<n;k++)if(x&(1<<k)){
                        x^=(1<<k);
                        break;
                    }
                }
            }
            to[i][c-'a']=x;
        }
    }
    f[0][0]=1;
    for(int i=1;i<=m;i++){
        for(char c='a';c<='z';c++){
            for(int z=0;z<(1<<n);z++)(f[i][to[z][c-'a']]+=f[i-1][z])%=Mod;
        }
    }
    for(int z=0;z<(1<<n);z++){
        int cnt=0;
        for(int i=0;i<n;i++)if(z&(1<<i))++cnt;
        (ans[cnt]+=f[m][z])%=Mod;
    }
    for(int i=0;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}


