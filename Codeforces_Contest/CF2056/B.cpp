#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int T,n,ans[N];
char s[N][N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            int pos=n;
            while(ans[pos])--pos;
            for(int j=i;j<=n;j++)if(s[i][j]=='1'){
                --pos;
                while(ans[pos])--pos;
            }
            ans[pos]=i;
        }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]),ans[i]=0;
        printf("\n");
    }
    return 0;
}


