#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
char s[N],t[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s %s",s+1,t+1);
        int p=n+1;
        for(int i=1;i<=n;i++)if(s[i]=='1'){
            p=i;
            break;
        }
        int tag=1;
        for(int i=n;i>=1;i--)if(s[i]!=t[i]&&i<p)tag=0;
        if(tag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}



