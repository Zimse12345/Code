#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
char s[N]; 

signed main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)if(i!=(n+1)/2)printf("%c",s[i]);
    return 0;
}


