#include <bits/stdc++.h>
using namespace std;

const int N=1024;
const char C[5]={'n','a','r','e','k'};
int T,n,m,f[N][8],tag[N];
char s[N];

signed main(){
    cin>>T;
    for(int i=0;i<5;i++)tag[(unsigned)C[i]]=1;
    while(T--){
        cin>>n>>m;
        f[0][1]=f[0][2]=f[0][3]=f[0][4]=-1e9;
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            for(int j=0;j<5;j++)f[i][j]=f[i-1][j];
            for(int j=0;j<5;j++){
                int p=j,v=0;
                for(int t=1;t<=m;t++)if(tag[(unsigned)s[t]]){
                    --v;
                    if(C[p]==s[t]){
                        p=(p+1)%5;
                        if(p==0)v+=10;
                    }
                }
                f[i][p]=max(f[i][p],f[i-1][j]+v);
            }
        }
        int ans=0;
        for(int i=0;i<5;i++)ans=max(ans,f[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}


