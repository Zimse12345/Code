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
        int tag=0;
        for(int i=1;i<n;i++)if(s[i]==s[i+1]){
            tag=1;
            for(int j=1;j<=i;j++)printf("%c",s[j]);
            printf("%c",s[i]=='z'?'a':s[i]+1);
            for(int j=i+1;j<=n;j++)printf("%c",s[j]);
            break;
        }
        if(!tag){
            for(int i=1;i<=n;i++)printf("%c",s[i]);
            printf("%c",s[n]=='z'?'a':s[n]+1);
        }
        printf("\n");
    }
    return 0;
}


