#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n;
char s[N],t[N];

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1,t=0;i<=n;i++){
        if(s[i]=='#')printf("#"),t=0;
        else{
            if(!t)printf("o"),t=1;
            else printf(".");
        }
    }
    printf("\n");
    return 0;
}


