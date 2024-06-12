#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int n,ans,tag[N][N];
char s[N][N];

signed main(){
    cin>>n;
    for(int i=1;i<n;i++)scanf("%s",s[i]+i+1);
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            int c=0;
            for(int k=i+1;k<j;k++)if(tag[i][k]&&s[k][j]=='1')c^=1;
            if(c!=s[i][j]-'0')++ans,tag[i][j]=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}


