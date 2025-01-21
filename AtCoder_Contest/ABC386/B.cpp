#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,ans;
char s[N];

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    int p=1;
    while(p<=n){
        ++ans;
        if(s[p]=='0'&&s[p+1]=='0')p+=2;
        else p+=1;
    }
    printf("%d\n",ans);
    return 0;
}


