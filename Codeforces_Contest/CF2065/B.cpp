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
        int ans=n;
        for(int i=n-1;i>=1;i--)if(s[i]==s[i+1]){
            ans=1;
            break;
        }
        printf("%d\n",ans);
    }
    return 0;
}


