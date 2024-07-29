#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int T,n,d;
char s[N][N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        for(int i=1;i<=n;i+=d){
            for(int j=1;j<=n;j+=d)printf("%c",s[i][j]);
            printf("\n");
        }
    }
    return 0;
}


