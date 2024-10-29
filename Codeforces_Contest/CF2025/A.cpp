#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m;
char s[N],t[N]; 

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        scanf("%s",t+1);
        n=strlen(s+1),m=strlen(t+1);
        int p=0;
        while(p<n&&p<m&&s[p+1]==t[p+1])++p;
        printf("%d\n",min(n+m-p+1,n+m)); 
    }
    return 0;
}


