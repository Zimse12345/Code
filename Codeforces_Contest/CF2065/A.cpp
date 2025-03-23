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
        for(int i=1;i<=n-2;i++)printf("%c",s[i]);
        printf("i\n");
    }
    return 0;
}


