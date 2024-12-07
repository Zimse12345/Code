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
        for(int t=0;t<10;t++)for(int i=2;i<=n;i++){
            if(s[i]-1>s[i-1])--s[i],swap(s[i],s[i-1]);
        }
        for(int i=1;i<=n;i++)printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}


