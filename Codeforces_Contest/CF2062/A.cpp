#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int ans=0;
        for(int i=1;i<=n;i++)if(s[i]=='1')++ans;
        printf("%d\n",ans);
    }
    return 0;
}


