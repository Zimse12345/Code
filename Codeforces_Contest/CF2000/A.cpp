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
        if(n>2&&s[1]=='1'&&s[2]=='0'&&s[3]>'0'&&(!(n==3&&s[3]=='1')))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


