#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n;
char s[N];

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)if(s[i]=='2')printf("2");
    return 0;
}


